def shrink(x):
    if len(x) == 0:
        return ''
    ans = x[0]
    for i in xrange(1, len(x)):
        if x[i] != x[i-1]:
            ans += x[i]
    return ans

def get_mid(c):
    if len(c) <= 2:
        return ''

    f = c[0]
    e = c[-1]
    i = 1
    j = len(c) - 2
    while i < len(c) and c[i] == f:
        i += 1
    while j >= 0 and c[j] == e:
        j -= 1
    return shrink(c[i:j+1])

def perm(x):
    ans = 1
    for i in xrange(1, x+1):
        ans *= i
        ans = ans % 1000000007
    return ans

def solve():
    n = input()
    cs = [x.strip() for x in raw_input().split()]
    assert n == len(cs)
    fs = {}
    es = {}
    mids = {}
    for i, c in enumerate(cs):
        fs.setdefault(c[0], [])
        f = c[0] + c[-1] if c[0] != c[-1] else c[0]
        fs[c[0]].append(f)
        es.setdefault(c[-1], [])
        es[c[-1]].append(f)
        mid = get_mid(c)
        #print 'mid:%s' % mid
        for x in mid:
            mids.setdefault(x, 0)
            mids[x] += 1
            if mids[x] > 1:
                #print 'mids %s = %s' % (x, mids[x])
                return 0
        if len(mid) > 0 and c[0] == c[-1]:
            #print 'c[0] == c[-1] %s' % c
            return 0
        cs[i] = f

    for mid in mids:
        for m in mid:
            if m in fs or m in es:
                #print 'mid in f or e: %s, %s' % (mid, m)
                return 0

    ans = 1
    l = len(cs) + 1
    ds = []
    while len(cs) < l:
        #print 'cs -- %s', cs
        l = len(cs)
        ss = {}
        for i, c in enumerate(cs):
            if len(c) == 1:
                ss.setdefault(c, 0)
                ss[c] += 1

        for k, v in ss.items():
            ans *= perm(v)

            for i in xrange(v):
                cs.remove(k)
                fs[k].remove(k)
                es[k].remove(k)
            if len(fs[k]) == 0:
                del fs[k]
            if len(es[k]) == 0:
                del es[k]

            if k not in fs and k not in es:
                ds.append(k)

        for k, v in fs.items():
            if len(v) > 1:
                #print k, v
                return 0
        for k, v in es.items():
            if len(v) > 1:
                #print k, v
                return 0
        changed = False
        for i, c in enumerate(cs):
            if changed:
                break
            for j in xrange(i + 1, len(cs)):
                if changed:
                    break
                d = cs[j]
                if c[0] == d[-1]:
                    if c[-1] == d[0]:
                        #print '%s and %s endless loop.' % (c, d)
                        return 0
                    changed = True
                    cs.remove(c)
                    cs.remove(d)
                    cs.append(d[0] + c[-1])
                elif c[-1] == d[0]:
                    changed = True
                    cs.remove(c)
                    cs.remove(d)
                    cs.append(c[0] + d[-1])

    #print 'cs:%s', cs
    #print 'ds:%s', ds
    ans *= perm(len(cs) + len(ds))
    ans = ans % 1000000007
    return ans


def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s' % (i, solve())

if __name__ == '__main__':
    main()
