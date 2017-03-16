def findK(r, t):
  a = 1
  b = 10**9
  while (b-a)>1:
    m = int((a+b)/2)
    if (2*r+2*m-1)*m<= t:
      a = m
    else:
      b = m
  return a

def solve():
  f = open("A-large.in", 'r')
  T = int(f.readline())
  for i in range(T):
    l = f.readline()
    [r,t] = [int(k) for k in l.split()]
    print "Case #%i:" %(i+1), findK(r,t)

solve()
