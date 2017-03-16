import sys
import random

T = int(sys.stdin.readline())

def to_base(n, b):
    ret = 0
    f = 1
    while n:
        ret += (n.pop() * f)
        f *= b
    return ret

for n in range(1, T+1):
    [K, C, S] = [int(i) for i in sys.stdin.readline().split()]

    if S * C < K:
        print "Case #{}: IMPOSSIBLE".format(n)

    else:
        to_check = range(0, K)
        while len(to_check) % C != 0:
            to_check.append(0)

        answer = []
        for i in range(len(to_check) / C):
            answer.append(to_base(to_check[(i*C):(i*C+C)], K) + 1)

        print "Case #{}: {}".format(n, ' '.join(str(x) for x in answer))
