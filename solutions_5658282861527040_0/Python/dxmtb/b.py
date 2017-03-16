import sys

T = int(raw_input())

for i in xrange(T):
        sys.stdout.write('Case #%d: ' % (i+1))
        A, B, K = [int(x) for x in raw_input().split()]
        ans = 0
        for a in xrange(A):
                for b in xrange(B):
                        if (a & b) < K:
                                ans += 1
        print ans

        
