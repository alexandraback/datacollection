import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))

#def isweakprime(n):
#   return all(n%q!=0 for q in [2,3,5,7,11])
#def isprime(n):
#   return all(n%q!=0 for q in range(2,int(n**.5)+1))
#def brute(n):
#   for i in range(2**(n-2)):
#      j = 1<<(n-1) | i<<1 | 1
#      bs = [sum(b**i for i in range(n) if j&1<<i) for b in range(2,11)]
#      if not any(isweakprime(b) for b in bs):
#         yield j
#
#import itertools
#for n in range(2,33):
#   print('====', n, '====')
#   it = brute(n)
#   example = list(itertools.islice(it,500))
#   print('\n'.join(map(bin, example)))
#   count = sum(1 for _ in it) + len(example)
#   print('total', count, '({})'.format(count/2**(n-2)))


T, = read()
for testCase in range(T):
   n, j = read()
   print('Case #{}:'.format(testCase+1))
   for i in range(2**(n-2)):
      coin = 1<<(n-1) | i<<1 | 1
      bs = [sum(b**i for i in range(n) if coin&1<<i) for b in range(2,11)]
      ds = [[d for d in [2,3,5,7,11] if b%d==0] for b in bs]
      if all(ds):
         #print(bs)
         #print(ds)
         print(bin(coin)[2:], ' '.join(str(d[0]) for d in ds))
         j -= 1
         if j == 0: break

