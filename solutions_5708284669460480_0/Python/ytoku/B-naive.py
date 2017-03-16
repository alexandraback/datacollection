from itertools import *
import sys

def solve(K, L, S, keys, target):
    c = 0
    mmax = 0
    for pat in product(keys, repeat=S):
        s = "".join(pat)
        m = 0
        for i in range(S - L + 1):
            if s[i:i+L] == target:
                c += 1
                m += 1
        mmax = max(m, mmax)
    if mmax == 0:
        return 0
    return mmax - float(c)/pow(K, S)

T = int(sys.stdin.readline())
for _c in range(T):
    line = sys.stdin.readline().strip()
    K, L, S = map(int, line.split(" "))
    keys = sys.stdin.readline().strip()
    target = sys.stdin.readline().strip()
    
    print "Case #%d: %.7f" % (_c + 1, solve(K, L, S, keys, target))

