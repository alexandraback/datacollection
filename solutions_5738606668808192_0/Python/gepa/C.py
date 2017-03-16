import random
import sys

def findFactor(x, d):
    for i in [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]:
        a = 1
        m = 0
        for k in x[::-1]:
            if k == 1:
                m = (m + a) % i
            a = (a * d) % i
        if m == 0:
            return i
    return 0


def compute(N, J):
    r = {}
    while len(r) < J:
        x = [random.randrange(0, 2) for i in xrange(N)]
        x[0] = 1
        x[-1] = 1
        found = True
        z = [''.join(map(str, x))]
        if z[0] in r:
            continue
        for d in xrange(2, 11):
            k = findFactor(x, d)
            if k == 0:
                found = False
                break
            z.append(str(k))
        if found:
            r[z[0]] = ' '.join(z)
    return '\n'.join(r.values())


def parse():
    N, J = map(int, sys.stdin.readline().strip().split())
    return N, J


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d:\n%s" % (i + 1, result)
