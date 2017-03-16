#/usr/local/bin/python

from itertools import * 

def get_subset(M, N):
    ans = set()
    if N == 0:
        ans.add([])
        return ans
    for s in get_subset(M, N - 1):
        for x in xrange(2, M + 1):
            ss = list(s)
            ss.append(x)
            ans.add(ss)
    
    return ans

def powerset(s):
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

import sys
import math

T = int(sys.stdin.readline())


for caseno in xrange(T):
   print "Case #%d:" % (caseno + 1)
   R, N, M, K = [int(x) for x in sys.stdin.readline().split()]

   univ = combinations_with_replacement(range(2, M + 1), N)

   cache = dict()

   for sset in univ:
       pans = set()
       
       for s in powerset(sset):
           pr = 1
           for i in s:
               pr *= i
           pans.add(pr) 

       cache[sset] = pans

   for i in xrange(R):
        products = [int(x) for x in sys.stdin.readline().split()]

        maxCount = 0
        ans = [ ] 

        for key, value in cache.iteritems():
            c = 0
            for p in products:
                if p in value:
                    c += 1;
                else:
                    c = 0;
                    break;

            if c > maxCount:
                maxCount = count;
                ans = key

        print "".join([str(k) for k in ans])





    
