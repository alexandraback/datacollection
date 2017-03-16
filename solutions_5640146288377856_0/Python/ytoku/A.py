from itertools import permutations
import sys

T = int(sys.stdin.readline())
for _c in range(T):
    line = sys.stdin.readline().strip()
    R, C, W = map(int, line.split(" "))

    s = (C / W) * (R - 1)
    if C % W == 0:
        s += C / W - 1 + W
    else:
        s += C / W + W
    
    print "Case #%d: %d" % (_c + 1, s)

