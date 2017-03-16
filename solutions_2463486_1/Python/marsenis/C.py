precomputed = [ 1 ,4 ,9 ,121 ,484 ,10201 ,12321 ,14641 ,40804 ,44944 ,1002001 ,1234321 ,4008004 ,100020001 ,102030201 ,104060401 ,121242121 ,123454321 ,125686521 ,400080004 ,404090404 ,10000200001 ,10221412201 ,12102420121 ,12345654321 ,40000800004 ,1000002000001 ,1002003002001 ,1004006004001 ,1020304030201 ,1022325232201 ,1024348434201 ,1210024200121 ,1212225222121 ,1214428244121 ,1232346432321 ,1234567654321 ,4000008000004 ,4004009004004 ]
l = len(precomputed)

tests = int(raw_input())
for t in range(1, tests+1):
   (a, b) = map(int, raw_input().split())
   cnt = 0
   for i in range(0, l):
      if precomputed[i] >= a and precomputed[i] <= b:
         cnt += 1
   print 'Case #{0:d}: {1:d}'.format(t, cnt)

## Code for precomputation (used only once)
#from math import *
#
#def palin(n):
#   s = str(n)
#   l = len(s)
#
#   for i in range(0, l//2):
#      if (s[i] != s[l-1-i]): return False
#
#   return True
#
#tests = int(raw_input())
#for t in range(1, tests+1):
#   (a, b) = map(int, raw_input().split())
#
#   k = int(ceil(sqrt(a)))
#   kSq = k**2
#   cnt = 0
#   while (kSq <= b):
#      if (palin(k) and palin(kSq)):
#         cnt += 1
#         print 'Counting: {0:d} -> {1:d}'.format(k, kSq)
#      kSq = kSq + 2*k + 1
#      k += 1
#   print 'Case #{0:d}: {1:d}\n'.format(t, cnt)
#
