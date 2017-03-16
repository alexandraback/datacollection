import sys

def _try_composite(a, d, n, s):
  if pow(a, d, n) == 1:
    return False
  for i in range(s):
    if pow(a, 2**i * d, n) == n-1:
      return False
  return True
 
def is_prime(n):
  witness = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]
  if n in witness:
    return True

  d, s = n - 1, 0
  while not d % 2:
    d, s = d >> 1, s + 1

  return not any(_try_composite(a, d, n, s) for a in witness)

def base(ls, bs):
  vl = 0
  tot = bs**(len(ls) - 1)
  for i in ls:
    vl += int(i == '1') * tot
    tot /= bs
  return vl

def test_coin(ls):
  return sum([is_prime(base(ls, bs)) for bs in range(2, 11)]) == 0

mx = 12
candidates = ["1" + "{0:b}".format(i).zfill(mx) + "1" for i in range(2**mx)]
tot = [i for i in candidates if test_coin(i)]
#prime_list = [i for i in range(2, 2**22) if is_prime(i)] large
prime_list = [i for i in range(2, 2**18) if is_prime(i)]

t = int(raw_input())
a, b = raw_input().split()
if a == "16":
  tp = "small"
else:
  tp = "large"

if tp == "small":
  j = 50
  n = 1
  print "Case #1:"

  i = 0
  done = 0
  div_list = [0] * 15
  while done < j and i < len(tot):
    fl = False
    for k in range(2, 11):
      vl = base("11" * n + tot[i], k)
      divisor = 0
      while divisor < len(prime_list) and vl > prime_list[divisor] and vl % prime_list[divisor] != 0:
        divisor += 1

      if divisor == len(prime_list) or vl <= prime_list[divisor]:
        fl = True
        break
      div_list[k] = prime_list[divisor]
    
    if fl:
      i += 1
      continue
    done += 1

    sys.stdout.write("11" * n + tot[i])
    for k in range(2, 11):
      sys.stdout.write(" ")
      sys.stdout.write(str(div_list[k]))
    print ""
    i += 1
  
  if i == len(tot):
    exit(1)

if tp == "large":
  j = 500
  n = 9
  print "Case #1:"

  i = 0
  done = 0
  div_list = [0] * 15
  while done < j and i < len(tot):
    fl = False
    for k in range(2, 11):
      vl = base("11" * n + tot[i], k)
      divisor = 0
      while divisor < len(prime_list) and vl > prime_list[divisor] and vl % prime_list[divisor] != 0:
        divisor += 1

      if divisor == len(prime_list) or vl <= prime_list[divisor]:
        fl = True
        break
      div_list[k] = prime_list[divisor]
    
    if fl:
      i += 1
      continue
    done += 1

    sys.stdout.write("11" * n + tot[i])
    for k in range(2, 11):
      sys.stdout.write(" ")
      sys.stdout.write(str(div_list[k]))
    print ""
    i += 1
  
  if i == len(tot):
    exit(1)
