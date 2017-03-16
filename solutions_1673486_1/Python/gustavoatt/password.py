from sys import stdin

T = int(stdin.readline())
for i in range(1, T+1):
  line = stdin.readline().split()
  A, B = (int(x) for x in line)
  
  fail_p = [float(x) for x in stdin.readline().split()]
  mult = []

  r = 1.0
  for x in fail_p:
    r *= x
    mult.append(r)
  
  p = mult[len(fail_p) - 1]
  keep  = p * (B - A + 1) + (1 - p) * (B - A + 1 + B + 1)
  enter = B + 2 
  
  m = min(keep, enter)
  for backspace in xrange(A):
    good = 2 * backspace + (B-A) + 1
    bad  = 2 * backspace + (B-A) + 1 + B + 1
    p = mult[len(fail_p) - backspace - 1]
    
    m = min(m, good * p + bad * (1-p))
  
  print "Case #{0}: {1:.6f}".format(i, m)
    
    