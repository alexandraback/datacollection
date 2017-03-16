import sys

def solve(a, b):
  result = 0
  if a and b:
    for ty in (set(zip(*a)[1]) | set(zip(*b)[1])):
      aa = list(a)
      while aa and aa[0][1] != ty:
        aa.pop(0)
      bb = list(b)
      while bb and bb[0][1] != ty:
        bb.pop(0)
      
      if aa and bb:
        na, ta = aa[0]
        nb, tb = bb[0]

        rr = min(na, nb)
        na -= rr
        nb -= rr
        
        if na:
          aa[0] = (na, ty)
        else:
          aa.pop(0)
        
        if nb:
          bb[0] = (nb, ty)
        else:
          bb.pop(0)

        result = max(result, rr + solve(aa, bb))
  return result

T = int(raw_input())
for ttt in xrange(T):
  N, M = [int(x) for x in raw_input().split()]

  t = [int(x) for x in raw_input().split()]
  a = []
  i = 0
  while i < len(t):
    a.append((t[i], t[i+1]))
    i += 2

  t = [int(x) for x in raw_input().split()]
  b = []
  i = 0
  while i < len(t):
    b.append((t[i], t[i+1]))
    i += 2

  print "Case #%i: %i" % (ttt+1, solve(a, b))
  print >>sys.stderr, ttt+1
