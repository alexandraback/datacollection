import sys
from collections import defaultdict

def line():
    return sys.stdin.readline().strip()

def ints(s):
    return [int(t) for t in s.split()]

def solve(d):
    minT = max(d)
    #print 'minT:',minT
    if minT <= 3:
        return minT
    else:
        n = d[minT]
        del d[minT]
        a,b = minT/2, minT/2 + minT%2
        d[a] += n
        d[b] += n
        #print 'd:', d
        return min(minT, solve(d) + n)

def main():
    tc = int(line())
    for i in range(1,tc+1):
        d = int(line())
        ps = ints(line())
        d = defaultdict(int)
        for p in ps:
            d[p] += 1
        print 'Case #%s: %s' % (i, solve(d))

main()
