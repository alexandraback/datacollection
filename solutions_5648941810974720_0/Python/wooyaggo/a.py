import fileinput
from pprint import pprint 

mat = []
for s in ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]:
  row = [0] * 26
  for c in s:
    row[ord(c) - ord('A')] += 1
  mat.append(row)

from numpy import matrix
from numpy import linalg

A = matrix(mat).T
fi = fileinput.input()
T = int(next(fi))
for tc in range(1, T + 1):
  s = next(fi).strip()
  cnt = [0] * 26
  for c in s:
    cnt[ord(c) - ord('A')] += 1
  
  t = A.I * matrix(cnt).T
  res = ''
  for i in range(10):
    r = t.T[0, i]
    if r < 1e-9: 
      r = 0
    else:
      r = int(r + 1e-9)
    res += chr(ord('0') + i) * r
  
  print "Case #%d: %s" % (tc, res) 
  
