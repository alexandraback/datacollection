from sys import stdin

def calc(target, C, F, X):
  cookies = 0.0
  cps = 2.0
  farms = 0
  time = 0.0
  while farms < target:
    time += C/cps
    farms += 1
    cps += F
  return time + X/cps
  

TC = int(stdin.readline())

for tc in range(1, TC+1):
  result = "Case #%d: %.7f"
  C, F, X = (float(a) for a in stdin.readline().split())

  l = 0
  r = 100000
  while l < r:
    m1 = int(l + (r-l)/3)
    m2 = int(l + 2 * (r-l)/3)
    if m1 == m2:
      break

    x1 = calc(m1, C, F, X)
    x2 = calc(m2, C, F, X)
    if x1 < x2:
      r = m2
    else:
      l = m1 + 1

  print result % (tc, calc(l, C, F, X))

