import sys

buf = []

def dp(E, R, v, e, i):
    if i == len(v):
        return 0
    global buf
    if buf[e][i] != -1:
        return buf[e][i]
    best = 0
    for j in xrange(e + 1):
        new_e = e - j + R
        if new_e > E:
            new_e = E
        current = j * v[i] + dp(E, R, v, new_e, i + 1)
        if current > best:
            best = current
    buf[e][i] = best
    return best


def compute(E, R, v):
    global buf
    buf = [[-1] * (len(v)) for i in xrange(E + 1)]
    return dp(E, R, v, E, 0)


def parse():
    E, R, N = map(int, sys.stdin.readline().strip().split())
    v = map(int, sys.stdin.readline().strip().split())
    return E, R, v


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
            print "Case #%d: %s" % (i + 1, result)
