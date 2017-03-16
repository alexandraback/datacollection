import sys


def reverse(i):
  res = 0
  while i > 0:
    res = res * 10 + (i % 10)
    i = i // 10
  return res

def fill():
  res = [-1] * (10**6+5)
  res[1] = [1, -1]
  count = {}
  count[1] = [1]
  for i in range(1, 10**6):
    t = count[i]
    count[i+1] = []
    for x in t:
      if x+1 > 10**6:
        continue
      if res[x+1] == -1:
        #print x+1, res[x+1]
        res[x+1] = (i+1, x)
        count[i+1].append(x+1)
        #print x+1, res[x+1], count[2]
      x2 = reverse(x)
      if x2 < 1 or x2 > 1000000:
        continue
      if res[x2] == -1:
        res[x2] = (i+1, x)
        count[i+1].append(x2)
    #print count[i+1]
  return res


AA = fill()


def foo(ifile):
  a = int(ifile.readline().strip())
  return AA[a]

def foo2():
  cur = int(sys.argv[1])
  foo3(cur)

def foo3(cur):
  cur2 = cur
  res = AA[cur2]
  while cur2 - res[1] == 1:
    cur2 = res[1]
    res = AA[cur2]
  print cur, AA[cur], cur2, AA[cur2]
  foo3(res[1])


def guess(i2):
  if len(str(i2)) < 2:
    return AA[i2][0]
  if i2 % 10 == 0:
    return guess(i2-1)+1
  res = i2 % (10 ** ((len(str(i2))+1)//2)) - 1
  if res != 0:
    return res + guess(i2-res)
  if reverse(i2) == i2:
    return guess(i2-1)+1
  return guess(reverse(i2))+1

def foo4():
  a = int(sys.argv[1])
  print AA[a], guess(a)

def foo5():
  for i in range(1, 10**6+1):
    t1 = AA[i][0]
    t2 = guess(i)
    if t1 != t2:
      print i, AA[i], guess(i)

def main():
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, guess(int(sys.stdin.readline().strip())))

#main()
main()
