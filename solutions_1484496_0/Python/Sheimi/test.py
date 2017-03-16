#!/usr/bin/env python


def get_input(func):
    raw = raw_input().split(' ')
    return map(func, raw)


def compute(i):
    typed = get_input(int)
    n = typed[0]
    x = typed[1:]
    r = {}
    rl = []
    t = x.pop()
    r[t] = (t,)
    rl.append((t,))
    while x:
        a = x.pop()
        t = [(a,)]
        for y in rl:
            m = list(y)
            m.append(a)
            t.append(tuple(m))
        for y in t:
            total = sum(y)
            if total in r:
                s1 = map(str, y)
                s2 = map(str, r[total])
                s1 = ' '.join(s1)
                s2 = ' '.join(s2)
                print "Case #%d:" % i
                print s1
                print s2
                return
            r[total] = y
        rl.extend(t)
        


if __name__ == '__main__':
    i = int(raw_input())
    for x in xrange(i):
        compute(x + 1)
