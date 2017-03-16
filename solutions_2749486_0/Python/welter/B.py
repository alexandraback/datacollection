import sys

def solve():
    t = int(sys.stdin.readline().strip())

    for i in xrange(1, t + 1):
        x, y = map(int, sys.stdin.readline().strip().split())
        res = ''
        if x < 0:
            res += 'EW' * abs(x)
        else:
            res += 'WE' * abs(x)
        if y < 0:
            res += 'NS' * abs(y)
        else:
            res += 'SN' * abs(y)
        print 'Case #%d: %s' % (i, res)


if __name__ == "__main__":
    solve()

