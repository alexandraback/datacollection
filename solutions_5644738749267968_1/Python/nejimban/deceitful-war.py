import re
from sys import stdin
T = int(stdin.readline()) # ignored
cases = [tuple(sorted(float(z) for z in y.split()) for y in x.splitlines())
         for x in re.findall('\d\s+((?:0.\d+(?: 0.\d+)*\s+)+)', stdin.read(),
                    flags=re.S)]
for k, (A, B) in enumerate(cases, 1):
  w, dw = 0, 0
  Bc = B[:]
  for a in A:
    try:
      b = min(b for b in Bc if b > a)
    except ValueError:
      Bc.pop(0)
      w += 1
    else:
      Bc.remove(b)
  while B:
    b = B.pop()
    try:
      a = min(a for a in A if a > b)
    except ValueError:
      A.pop(0)
    else:
      A.remove(a)
      dw += 1
  print('Case #%d: %d %d' % (k, dw, w))
