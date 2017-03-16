from __future__ import print_function
from random import randint

if __name__ == '__main__':
    T = int(raw_input())
    for pb_i in xrange(T):
        t1, t2, K = [int(_) for _ in raw_input().split()]
        A = min(t1, t2)
        B = max(t1, t2)

        c = 0
        for x1 in xrange(A):
            if x1 < K:
                c+=B
            else:
                c+=K
                for x2 in xrange(K, B):
                    if ((x1 & x2) < K):
                        c+=1
        print("Case #{}: {}".format(pb_i+1, c))