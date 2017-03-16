import sys


def solve(c, f, x):
    rate = 2
    t = 0
    while c/rate + x/(rate+f) < x/rate:
        t += c/rate
        rate += f
    return t + x/rate


if __name__ == '__main__':
    infile = sys.stdin
    t = int(infile.readline())
    for i in xrange(1, t+1):
        (c, f, x) = map(float, infile.readline().split())
        print "Case #%d: %.7f" % (i, solve(c, f, x))
