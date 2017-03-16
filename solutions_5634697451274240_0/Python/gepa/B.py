import sys


def compute(S):
    c = sum(map(lambda x: 0 if x[0] == x[1] else 1, zip(S, S[1:] + '+')))
    return c
    return c if S[-1] == '+' else c + 1


def parse():
    return sys.stdin.readline().strip(),


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
