from util import *
import math

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in xrange(num):
        C,F,X = map(float, r.next().split(" "))

        n = (X * F - 2. * C) / (C * F)
        n = 0. if n < 0. else n
        n = int(math.floor(n))

        cost = 0.

        for i in xrange(n):
            cost += (C / (2. + i * F))

        cost += (X / (2. + n * F))

        ans.append("%0.7f" % cost)
    write("output", ans)

if __name__ == '__main__':
    main()
