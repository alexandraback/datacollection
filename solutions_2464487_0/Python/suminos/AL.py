
def f(x, r):
  return (2*r+1)*x + 2*x*(x-1);

def solve(r, t):
  lb = 0;
  ub = 2**60;
  
  for k in range(1000):
    m = (lb + ub) / 2;
    if f(m, r) <= t:
      lb = m;
    else:
      ub = m;
  
  return lb;

T = int(raw_input());
for tn in range(T):
  r, t = map(int, raw_input().split());
  print "Case #" + str(tn+1) + ": " + str(solve(r, t));
