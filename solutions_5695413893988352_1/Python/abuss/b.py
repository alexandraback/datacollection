T = int(raw_input())


def mins(s):
    if not s: return ''
    c, r = s[0], s[1:]
    if c == '?':
        return '0' + mins(r)
    else:
        return c + mins(r)


def maxs(s):
    if not s: return ''
    c, r = s[0], s[1:]
    if c == '?':
        return '9' + maxs(r)
    else:
        return c + maxs(r)


def absdiff(a, b):
    return abs(int(a) - int(b))


def match(a, b):
    if not a: return '', ''
    ac, ar = a[0], a[1:]
    bc, br = b[0], b[1:]
    ra, rb = match(ar, br)
    ps = []

    def add_p(ap, bp):
        ps.append((absdiff(ap, bp), ap, bp))

    al = [ac]
    bl = [bc]
    if ac == '?' and bc == '?':
        al = '0123456789'
        bl = '0123456789'
    elif ac == '?':
        al = '0123456789'
    elif bc == '?':
        bl = '0123456789'

    else:
        if ac == bc:
            return ac + ra, bc + rb
        if ac > bc:
            return ac + mins(ar), bc + maxs(br)
        else:
            return ac + maxs(ar), bc + mins(br)
    for a in al:
        for b in bl:
            add_p(a + ra, b + rb)
            add_p(a + ra, b + mins(br))
            add_p(a + ra, b + maxs(br))
            add_p(a + mins(ar), b + rb)
            add_p(a + maxs(ar), b + rb)
            add_p(a + maxs(ar), b + mins(br))
            add_p(a + mins(ar), b + maxs(br))

    best = sorted(ps)[0]
    return best[1], best[2]


def poss(x):
    if not x:
        yield ''
        return
    a = x[0]
    r = x[1:]
    p = list(poss(r))
    if a == '?':
        for c in '0123456789':
            for y in p:
                yield c + y
    else:
        for y in p:
            yield a + y


for t in range(T):
    a, b = raw_input().split()
    # print a, b
    a, b = match(a, b)
    # ap, bp = list(poss(a)), list(poss(b))
    # p = []
    # for x in ap:
    #     for y in bp:
    #         p.append((abs(int(x) - int(y)), x, y))
    # _, ap, bp = sorted(p)[0]
    print "Case #%d:" % (t + 1), a, b
    s = 0
