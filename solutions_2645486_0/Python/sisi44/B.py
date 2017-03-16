import operator
   
def gain(v, E, R, re):
  n = len(v)
  v2 = reversed(v)
  if n is 0:
    return 0
  iMax, vMax = max(enumerate(v2), key = operator.itemgetter(1))
  iMax = n-1 - iMax
  s = E + (n-iMax)*R- re
  if E<=0:
    return 0
  #print E, R, s, re, vMax
  if E<= s:
    return E * vMax + gain(v[:iMax], E, R, E) + gain(v[iMax+1:], R, R, re)
  else:
    return s * vMax + gain(v[:iMax], E, R, E) + gain(v[iMax+1:], R-s, R, re)

def solve():
  #f = open("in.txt", 'r')

  f = open("B-small-attempt7.in", 'r')
  T = int(f.readline())
  for i in range(T):
    l = f.readline()
    [E,R,N] = [int(k) for k in l.split()]
    l = f.readline()
    v = [int(k) for k in l.split()]
    print "Case #%i:" %(i+1), gain(v, E, R, R)

solve()
