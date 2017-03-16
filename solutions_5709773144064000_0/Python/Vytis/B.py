#!/usr/bin/env python


def solve():
    c, f, x = map(float, raw_input().strip().split())
    p = 2
    t = 0
    best = x / p
    while True:
        t += c / p
        p += f
        tt = t + x / p
        if tt < best:
            best = tt
        else:
            break
    return '{:.7f}'.format(best)


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
