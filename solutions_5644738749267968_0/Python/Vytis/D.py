#!/usr/bin/env python


def war(naomi, ken):
    i = 0
    p = 0
    for x in naomi:
        while i < len(ken) and ken[i] < x:
            i += 1
            p += 1
        i += 1
    return p

def deceit(naomi, ken):
    i = 0
    for x in naomi:
        if x > ken[i]:
            i += 1
    return i

def solve():
    n = int(raw_input().strip())
    naomi = map(float, raw_input().strip().split())
    ken = map(float, raw_input().strip().split())
    naomi.sort()
    ken.sort()
    y = deceit(naomi, ken)
    z = war(naomi, ken)
    return '{} {}'.format(y, z)


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
