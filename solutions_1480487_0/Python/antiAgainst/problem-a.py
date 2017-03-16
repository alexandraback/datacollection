#!/usr/bin/python2

def isCurrentPossible(pv, tot, idx, k):
    m = pv[idx] + k * tot
    totdiff = 0
    for i in range(len(pv)):
        if pv[i] < m and i != idx:
            totdiff += m - pv[i]
    if totdiff <= (1 - k) * tot:
        return False
    else:
        return True

if __name__ == "__main__":

    f = open('A-small-attempt3.in')
    tc = int(f.readline().strip())

    for t in range(tc):
        print "Case #%d:" % (t + 1),

        n, rest = f.readline().split(" ", 1)
        n = int(n)
        pv = rest.split()
        pv = [int(i) for i in pv]
        tot = sum(pv)

        for i in range(n):
            l = 0
            r = 100000000
            while (l < r - 1):
                if isCurrentPossible(pv, tot, i, float(l+r)/200000000):
                    r = (l + r) / 2
                else:
                    l = (l + r) / 2
            print "%f" % (float(l) / 1000000),
        print
