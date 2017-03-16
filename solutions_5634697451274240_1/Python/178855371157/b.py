import sys
import random

T = int(sys.stdin.readline())

for n in range(1, T+1):
    S = sys.stdin.readline().strip()

    S = S + '+'

    last = S[0]
    answer = 0
    for p in S[1:]:
        if last != p:
            answer += 1
        last = p

    print "Case #{}: {}".format(n, answer)
