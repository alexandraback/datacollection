from math import log10
from math import floor

#f = open('count.txt', 'r')
f = open('A-small-attempt0.in', 'r')
g = open('count.out', 'w')
lines = int(f.readline())
count = 1

def attempt(n,p,q,r):
  rem = int(str(n)[-1*r:])
  if rem == 0:
    rev = int(str(int(str(n)[:q])-1)[::-1])
    t = rev + (10 ** (r))
  else:
    rev = int(str(n)[:q][::-1])
    t = rev + rem
  return min(t, n - 10 ** p)

while count <= lines:
  n = int(f.readline())
  p = floor(log10(n))

  if n < 10:
    c = n
  else:
    c = 0
    for i in range(1, p+1):
      q = i // 2
      r = i - q
      c += (10**(q) - 1) + (10**(r) - 1) + 1

    d = p + 1
    if d % 2 == 0:
      q = d // 2
      r = d // 2
      c += attempt(n,p,q,r)
    else:
      a = attempt(n,p,d//2,(d//2)+1)
      b = attempt(n,p,(d//2)+1,d//2)
      c += min(a,b)
    #print(c)

  g.write('Case #' + str(count) + ': ' + str(c) + '\n')
  count += 1
  
f.close()
g.close()
