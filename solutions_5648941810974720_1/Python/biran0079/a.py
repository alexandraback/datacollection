from numpy import abs, diag, dot, zeros
import numpy as np
from numpy.linalg import lstsq, inv, norm

d=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
a=[]
for i in range(10):
  r=[0]*26
  for c in d[i]:
    r[ord(c)-ord('A')]+=1
  a.append(r)
A=[]
for i in range(26):
  r=[]
  for j in range(10):
    r.append(a[j][i])
  A.append(r)
n=int(raw_input())
for t in range(n):
  s=raw_input()
  b=[0]*26
  for c in s:
    b[ord(c)-ord('A')]+=1
  res=[]
  i=0
  for n in np.linalg.lstsq(A, b)[0]:
    res += [str(i)] * int(n+1e-6)
    i+=1
  print 'Case #{}: {}'.format(t+1,"".join(res))
