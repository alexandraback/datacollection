import sys


def compute(K, C, S):
    if C * S < K:
        return "IMPOSSIBLE"
    r = []
    q = range(K)
    i = 0
    while i < K:
        r.append(str(reduce(lambda x, y: K * x + y, q[i:i+C], 0) + 1))
        i += C
    return ' '.join(r)


def parse():
    K, C, S = map(int, sys.stdin.readline().strip().split())
    return K, C, S


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
