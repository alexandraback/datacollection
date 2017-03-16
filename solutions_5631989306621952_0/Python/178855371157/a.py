import sys
import random

T = int(sys.stdin.readline())

for n in range(1, T+1):
    S = sys.stdin.readline().strip()

    word = S[0]
    for c in S[1:]:
        if c >= word[0]:
            word = c + word
        else:
            word = word + c

    print "Case #{}: {}".format(n, word)
