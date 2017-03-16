import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))

T, = read()
for testCase in range(T):
   n, = read()
   if n == 0:
      k = 'INSOMNIA'
   else:
      k, s = 0, set()
      while len(s) != 10:
         k += n
         s.update(str(k))
   print('Case #{}: {}'.format(testCase+1, k))

