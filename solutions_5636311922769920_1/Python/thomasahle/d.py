import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))

import itertools
def expand(k,c,orig):
   s = orig
   for _ in range(c):
      s = ''.join('g'*k if ch=='g' else orig for ch in s)
   return s

def test(k,c,ps):
   strings = [expand(k,c,'l'*i+'g'+'l'*(k-i-1)) for i in range(k)]
   return all(any(s[p]=='g' for p in ps) for s in strings)

f = lambda k,c,a: sum((i+a)*k**(c-i-1) for i in range(min(k-a,c)))

T, = read()
for testCase in range(T):
   k,c,s = read()
   if k/c > s:
      res = 'IMPOSSIBLE'
   else:
      l = min(k,c)
      res = [f(k,c,a) for a in range(0,k,l)]
      if k**c < 10**3:
         print(k, c, test(k,c,res))
      res = ' '.join(str(p+1) for p in res)
   print('Case #{}: {}'.format(testCase+1, res))

