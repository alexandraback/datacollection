
import sys

fin = sys.stdin
fout = sys.stdout

T = int(fin.readline())

for t in range(T):
    R,C,W = map(int, fin.readline().split())

    cost = max(0, R-1) * (C//W)
    if C%W==0:
        cost += C//W + W-1
    else:
        cost += C//W + W
    fout.write("Case #%i: %i\n" % (t+1, cost))
