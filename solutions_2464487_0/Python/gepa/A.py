import sys


def compute(r, t):
    left = 0
    right = 10000000000
    while left < right:
        middle = (left + right) // 2
        x = 2 * r * middle + 2 * middle * middle - middle
        if x <= t:
            left = middle + 1
        else:
            right = middle
    return right - 1


def parse():
    r, t = map(int, sys.stdin.readline().strip().split())
    return r, t


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
