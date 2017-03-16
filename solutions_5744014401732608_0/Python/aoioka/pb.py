# -*- coding: utf-8 -*-

def inp(s, t):
    if t == 0:
        return 1

    ret = 0
    for e in s:
        if e[1] == t:
            ret += 1

    return ret


def outp(s, t, b):
    if outp == b - 1:
        return 1

    ret = 0
    for e in s:
        if e[0] == t:
            ret += 1

    return ret


def solve():
    b, m = map(int, raw_input().split())
    graph = [[False] * b for i in xrange(b)]

    cnt = 1
    for i in xrange(b - 1):
        graph[i][i + 1] = True

    ss = [(set(), 1)]
    for i in xrange(b - 1):
        ss[0][0].add((i, i + 1))

    possible = False
    llst = []
    while ss != []:
        nss = []
        for i in xrange(len(ss)):
            for j in xrange(b - 1):
                for k in xrange(j + 1, b):
                    if (j, k) not in ss[i][0]:
                        e = ss[i][0].copy()
                        e.add((j, k))
                        new = (e, ss[i][1] + inp(ss[i][0], j) * outp(ss[i][0], k, b))
                        if new not in nss:
                            nss.append(new)

        for e in ss:
            if e[1] == m:
                possible = True
                llst = e[0].copy()
                ss = []
                break

        if not possible:
            ss = nss

    if not possible:
        print 'IMPOSSIBLE'
        return

    for e in llst:
        graph[e[0]][e[1]] = True

    print 'POSSIBLE'
    for row in graph:
        r = ['1' if e else '0' for e in row]
        print ''.join(r)


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        print 'Case #%d:' % i,
        solve()


if __name__ == '__main__':
    main()
