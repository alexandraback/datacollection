import sys
import math

sys.stdin = open('/home/hongjy/Downloads/A-large.in')
sys.stdout = open('A.txt', 'w')

EPS = 1e-8
def get(n, r):
    return n * (2 * r + 1) + 2* n * (n - 1)

def solve(r, t):
    low = 0
    hi = t / r
    while low < hi:
        mid = (low + hi) >> 1;
        if get(mid, r) <= t:
            low = mid + 1
        else:
            hi = mid
    if get(hi, r) <= t:
        hi += 1
    return hi - 1

T = input()
for cas in xrange(T):
    sys.stdout.write("Case #%d: " % (cas + 1))
    line = raw_input()
    parts = line.split()
    r = int(parts[0])
    t = int(parts[1])
    ret = solve(r,t)
    print ret
    
