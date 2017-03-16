import sys
import fractions

if len(sys.argv)<2:
  exit()
  
def power2(a):
  i = 0
  while a > 1:
    if a%2 == 1:
      return False, i
    a /= 2
    i+=1
  return True, i
      

fname = sys.argv[1]
f = open(fname, "r")

T = int(f.readline())






for i in range(T):
  p,q = [int(x) for x in f.readline().strip().split('/')]
 
  g = fractions.gcd(p,q)
  p/=g
  q/=g
  
  r,g =  power2(q)
  if not r:
    print "Case #%d: impossible" % (i+1)  
  else:
    t = 1
    while p < q/2:
      t+=1
      q /= 2
    print "Case #%d: %d" % (i+1, t)  
  
f.close()