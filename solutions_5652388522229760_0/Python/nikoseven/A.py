def tobit(x):
  r = 0
  while x > 0:
    c = x % 10
    x /= 10
    r = r | ( 1 << c )
  return r

def solve(n):
  m = 0
  v = 0
  x = 0
  while x != 1023:
    v = v + n
    x = x | tobit(v)
  return v

T = int(raw_input())
for _case in range(T):
  n = int(raw_input())
  if n == 0:
    print "Case #%d: INSOMNIA" % (_case+1)
  else:
    print "Case #%d: %d" % (_case+1, solve(n))
