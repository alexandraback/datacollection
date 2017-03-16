from operator import mul
import fileinput

def lowest(slist):
  newslist = slist[:]
  for i in range(len(newslist)):
    if newslist[i] == '?':
      newslist[i] = '0'
  return newslist

def highest(slist):
  newslist = slist[:]
  for i in range(len(newslist)):
    if newslist[i] == '?':
      newslist[i] = '9'
  return newslist

def int_val(slist):
  return int("".join(slist))

def diff(slist1, slist2):
  return abs(int_val(slist1) - int_val(slist2))

def better((s1try1, s2try1), (s1try2, s2try2)):
  if diff(s1try1, s2try1) < diff(s1try2, s2try2):
    return (s1try1, s2try1)
  elif diff(s1try1, s2try1) > diff(s1try2, s2try2):
    return (s1try2, s2try2)
  else:
    if int_val(s1try1) < int_val(s1try2):
      return (s1try1, s2try1)
    elif int_val(s1try1) > int_val(s1try2):
      return (s1try2, s2try2)
    else:
      if int_val(s2try1) < int_val(s2try2):
        return (s1try1, s2try1)
      else:
        return (s1try2, s2try2)

def solve(slist1, slist2):
  if len(slist1) == 0:
    assert(len(slist2) == 0)
    return ([], [])
  sl1 = slist1[:]
  sl2 = slist2[:]
  if sl1[0] == '?' and sl2[0] == '?':
    sl1[0] = '0'
    sl2[0] = '1'
    (s1try1, s2try1) = solve(sl1, sl2)
    sl1[0] = '1'
    sl2[0] = '0'
    (s1try2, s2try2) = solve(sl1, sl2)
    sl1[0] = '0'
    sl2[0] = '0'
    (s1try3, s2try3) = solve(sl1, sl2)
    return better((s1try1, s2try1),better((s1try2, s2try2),(s1try3, s2try3)))
  elif sl1[0] == '?':
    if sl2[0] != '0':
      sl1[0] = str(int(sl2[0])-1)
      (s1try1, s2try1) = solve(sl1, sl2)
    else:
      (s1try1, s2try1) = solve(['9']*20, ['0']*20)
    if sl2[0] != '9':
      sl1[0] = str(int(sl2[0])+1)
      (s1try2, s2try2) = solve(sl1, sl2)
    else:
      (s1try2, s2try2) = solve(['9']*20, ['0']*20)
    sl1[0] = sl2[0]
    (s1try3, s2try3) = solve(sl1, sl2)
    return better((s1try1, s2try1),better((s1try2, s2try2),(s1try3, s2try3)))
  elif sl2[0] == '?':
    if sl1[0] != '0':
      sl2[0] = str(int(sl1[0])-1)
      (s1try1, s2try1) = solve(sl1, sl2)
    else:
      (s1try1, s2try1) = solve(['9']*20, ['0']*20)
    if sl1[0] != '9':
      sl2[0] = str(int(sl1[0])+1)
      (s1try2, s2try2) = solve(sl1, sl2)
    else:
      (s1try2, s2try2) = solve(['9']*20, ['0']*20)
    sl2[0] = sl1[0]
    (s1try3, s2try3) = solve(sl1, sl2)
    return better((s1try1, s2try1),better((s1try2, s2try2),(s1try3, s2try3)))
  else:
    if int(sl1[0]) < int(sl2[0]):
      s1 = highest(sl1[1:])
      s2 = lowest(sl2[1:])
      return ([sl1[0]] + s1, [sl2[0]] + s2)
    elif int(sl1[0]) > int(sl2[0]):
      s1 = lowest(sl1[1:])
      s2 = highest(sl2[1:])
      return ([sl1[0]] + s1, [sl2[0]] + s2)
    else:
      (s1, s2) = solve(sl1[1:], sl2[1:])
      return ([sl1[0]] + s1, [sl2[0]] + s2)

def expand(s, l):
  assert(l >= len(s))
  return "0" * (l - len(s)) + s

#s1 is the scoreboard string
def string_match (s1, s2):
  if (len(s1) < len(s2)):
    return False
  s2 = expand(s2, len(s1))
  for idx in range(len(s1)):
    if s1[idx] != '?' and s1[idx] != s2[idx]:
      return False
  return True


num_cases = int(raw_input())
for case in range(1,num_cases+1):
  shuffled_num = raw_input()
  s = shuffled_num.split(" ");
  C = list(s[0])
  J = list(s[1])
  (clist, jlist) = solve(C,J)
  print("Case #%d: %s %s" % (case, "".join(clist), "".join(jlist)))
