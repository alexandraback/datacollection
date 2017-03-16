import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

ERROR = (10**20, 0)

def best(x1y1, x2y2):
   x1, y1 = x1y1
   x2, y2 = x2y2
   dif, x, y = min(((abs(x1-y1), x1, y1), (abs(x2-y2), x2, y2)))
   return x, y

def fit(a, b, i, j):
   for k in range(len(a)):
      if a[k] != '?' and a[k] != (i//10**k)%10:
         return False
      if b[k] != '?' and b[k] != (j//10**k)%10:
         return False
   return True

T, = read()
for testCase in range(T):
   a, b = read(str)
   a = [(int(c) if c != '?' else '?') for c in a][::-1]
   b = [(int(c) if c != '?' else '?') for c in b][::-1]

   C = len(a)

   res = ERROR
   if C == 3:
      for i in range(10**3):
         for j in range(10**3):
            if fit(a, b, i, j):
               res = best(res, (i, j))
   if C == 2:
      for i in range(10**2):
         for j in range(10**2):
            if fit(a, b, i, j):
               res = best(res, (i, j))
   if C == 1:
      for i in range(10**1):
         for j in range(10**1):
            if fit(a, b, i, j):
               res = best(res, (i, j))

   x, y = res
   resx = str(x).zfill(C)
   resy = str(y).zfill(C)

   print('Case #{}: {} {}'.format(testCase+1, resx, resy))

