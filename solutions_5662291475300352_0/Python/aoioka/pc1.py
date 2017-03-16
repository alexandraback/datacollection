# -*- coding: utf-8

def solve():
    n = int(raw_input())
    dhm = []
    for i in xrange(n):
        dhm.append(map(int, raw_input().split()))
    hikers = []
    for e in dhm:
        for i in xrange(e[1]):
            hikers.append((e[0], e[2]+i))
    s = 0 if hikers[0][1] > hikers[1][1] else 1
    f = 0 if s == 1 else 0
    xs = hikers[s][0]
    ts = hikers[s][1]
    xf = hikers[f][0]
    tf = hikers[f][1]
    if ts == tf:
        return 0
    if (360 - xs) * ts < 360 * tf + (360 - xf) * tf:
        return 0
    return 1

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%d: %d' % (i, solve())

if __name__ == '__main__':
    main()
