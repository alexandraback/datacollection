d1 = dict()
d1[(0, 0)] = ''
d2 = dict()
d2[0] = []
d2[0] += [(0, 0)]

for i in range(1, 501):
   #print i
   d2[i] = []
   for (x0, y0) in d2[i-1]:
      for (x, y, d) in [(x0+i, y0, 'E'), (x0-i, y0, 'W'), (x0, y0+i, 'N'), (x0, y0-i, 'S')]:
         if not (x, y) in d1:
            if x > 100 or x < -100 or y > 100 or y < -100: continue
            d1[(x, y)] = d1[(x0, y0)] + d
            d2[i] += [(x, y)]

def solve(X, Y):
   return d1[(X, Y)]

from sys import stdin

T = int(stdin.readline())
for t in range(T):
   x, y = map(int, stdin.readline().split())
   print "Case #{}: {}".format(t+1, solve(x, y))
