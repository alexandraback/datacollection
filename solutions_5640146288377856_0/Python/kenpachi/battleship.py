import sys

with sys.stdin as f:
    T = int(f.readline())
    for t in range(T):
        tokens = f.readline().split()
        R = int(tokens[0])
        C = int(tokens[1])
        W = int(tokens[2])
        print "Case #%d: %d" % (t+1, R*(C/W + W - (0, 1)[(C%W) == 0]))
