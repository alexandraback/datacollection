def root(s, g):
  g = int(g)
  while g**2 > s: g -= 1
  while (g+1)**2 <= s: g += 1
  return g
for i in range(1,input()+1):
  r, t = map(int, raw_input().split())
  a = 2
  b = 2*r - 1
  c = -t
  disc = b**2 - 4*a*c
  R = root(disc, disc**.5)
  ans = (R - b)/(2*a)
  print 'Case #%i:'%i, ans
