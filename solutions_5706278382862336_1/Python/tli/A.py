from fractions import gcd
t = int(raw_input())

def is_perfect_power(n):
  while n > 1:
    if n % 2 == 0:
      n /= 2
    else:
      return False
  return True

def possible(p, q):
  g = gcd(p, q)
  p /= g
  q /= g

  if not is_perfect_power(q):
    return -1

  if p == q or p == 0:
    return 0

  else:
    p *= 2
    g = gcd(p, q)
    p /= g
    q /= g

    if p > 2 * q:
      return -1
    else:
      a = 0
      if p >= q:
        a = possible(p - q, q)
        if a < 0:
          return -1
        else:
          return 1
      else:
        a = possible(p, q)
        if a < 0:
          return -1
        else:
          return a + 1

for i in xrange(t):
  p, q = map (int, raw_input().split("/"))

  a = possible(p, q)

  if a >= 0:
    print "Case #" + str(i + 1) + ":", a
  else:
    print "Case #" + str(i + 1) + ": impossible"



