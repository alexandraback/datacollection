import sys
import random

T = int(sys.stdin.readline())

for n in range(1, T+1):
    [K, C, S] = [int(i) for i in sys.stdin.readline().split()]

    answer = [(K**(C-1))*i for i in range(1, K+1)]
    print "Case #{}: {}".format(n, ' '.join(str(x) for x in answer))
