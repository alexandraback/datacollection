import math, sys

def time(p, e):
    spots = int(math.ceil(p/e))
    maxspot = int(math.ceil(p/spots))

    return maxspot + spots - 1

def test():
    D = int(input())
    ps = list(map(int, input().split(' ')))
    mp = max(ps)

    best = mp

    for i in range(1, mp):
        switches = sum(int(math.ceil(p/i))-1 for p in ps)
        cur = i + switches
        best = min(cur, best)

    return best

cases = int(input())

for case in range(1, cases+1):
    print('Case #%d: %s'%(case, test()))