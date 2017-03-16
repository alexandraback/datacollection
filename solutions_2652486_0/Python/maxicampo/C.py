f=open("C.in","r")
g=open("sets.out","w")
import math

def primeFact (v, w):
    if v < w:
        return []
    if v % w == 0:
        return [w] + primeFact (v / w, 2)
    return primeFact (v, w + 1)

f.readline()
f.readline()
g.write("Case #1:\n")

for j in range(0,100):
  L = map(int,f.readline().split( ))
  M = max(L)
  X = primeFact(M,2)
 
  if len(X) == 3:
    ans = ''.join(str(e) for e in X)
  else:
    if len(X) < 3:
      ans = '222'
    else:
      if len(X) == 4:
        X.sort()
        X.remove(2)
        X.remove(2)
        X.append(4)
        ans = ''.join(str(e) for e in X)
      elif len(X) == 5:
        X.sort()
        X.remove(2)
        X.remove(2)
        X.remove(2)
        X.remove(2)
        X.append(4)
        X.append(4)
        ans = ''.join(str(e) for e in X)
      elif len(X) == 6:
        X.sort()
        X.remove(2)
        X.remove(2)
        X.remove(2)
        X.remove(2)
        X.remove(2)
        X.remove(2)
        X.remove(4)
        X.append(4)
        X.append(4)
        ans = ''.join(str(e) for e in X)
  g.write(ans+"\n")
