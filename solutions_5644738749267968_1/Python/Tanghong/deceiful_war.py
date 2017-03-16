import sys

def solve(naomi, ken, n):
    naomi.sort()
    ken.sort()
    z = 0
    j = 0
    k = n-1
    for i in xrange(n-1, -1, -1):
        if naomi[i] > ken[k]:
            z += 1
            j += 1
        else:
            k -= 1

    y = 0
    j = 0
    k = n - 1
    for i in xrange(n):
        if naomi[i] < ken[j]:
            k -= 1
        else:
            j += 1
            y += 1

    return y, z


if __name__ == '__main__':
    f = sys.stdin
    t = int(f.readline())
    for i in xrange(1, t+1):
        n = int(f.readline())
        naomi = map(float, f.readline().split())
        ken = map(float, f.readline().split())
        y, z = solve(naomi, ken, n)
        print "Case #%d: %d %d" % (i, y, z)
