import sys
from math import sqrt

def is_pal(n):
  l = list(str(n))
  l_rev = list(reversed(l))
  return l == l_rev 

target = 10**7

nbs = []
current_index, current_pal, d = 0, 0, 0
while current_index < target:
  d += 1
  if is_pal(d) and is_pal(d*d):
    while current_index < d:
      nbs.append(current_pal)
      current_index += 1
    current_pal += 1

def f(lo, up):
  slo = int(sqrt(lo))
  if slo * slo != lo: slo += 1
  sup = int(sqrt(up))
  return nbs[sup] - nbs[slo-1]

samples = int(sys.stdin.readline().rstrip())
for i in range(samples):
  line = sys.stdin.readline().rstrip()
  [lo, up] = line.split()
  print "Case #%d: %s" % (i+1, f(int(lo), int(up)))

