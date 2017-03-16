import random

N = 32
J = 500

numbers = set()
print('Case #1:')
j = 0

def findm(n, M = 1000000):
  x = 2
  while x * x <= n and x <= M:
    if n % x == 0: return x
    x += 1
  return None

while j < J:
  x = tuple(random.randint(0, 1) for i in range(N-2))
  if x in numbers: continue
  numbers.add(x)
  bad = False
  ml = []
  for i in range(2,11):
    n = 1
    for y in x:
      n = n * i + y
    n = n * i + 1
    p = findm(n)
    if p is None:
      bad = True
      break
    ml.append(p)
  if not bad:
    j += 1
    print('1' + ''.join(str(y) for y in x) + '1 ' +' '.join(str(p) for p in ml)) 
