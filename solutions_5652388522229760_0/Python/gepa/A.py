import sys


def compute(N):
    used = set()
    c = N
    for i in xrange(100):
        x = map(int, str(c))
        used.update(x)
        if len(used) == 10:
            return c
        c += N
    return "INSOMNIA"


def parse():
    return int(sys.stdin.readline().strip()),


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
