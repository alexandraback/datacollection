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


remainder = 0


def match(a, b):
    global remainder
    if not a: return '', ''
    ac, ar = a[0], a[1:]
    bc, br = b[0], b[1:]
    ra, rb = match(ar, br)
    if ac == '?' and bc == '?':
        best = sorted([
            ('0', '0', abs(int('0' + ra) - int('0' + rb))),
            ('0', '1', abs(int('0' + ra) - int('1' + rb))),
            ('1', '0', abs(int('1' + ra) - int('0' + rb)))
        ], key=lambda x: x[2])[0]
        return best[0] + ra, best[1] + rb
    if ac == bc:
        return ac + ra, bc + rb
    if ac == '?':
        aopts = []
        if bc > '0':
            aopts.append(chr(ord(bc) - 1))
        aopts.append(bc)
        if bc < '9':
            aopts.append(chr(ord(bc) + 1))
        best = sorted([
                          (a, bc, abs(int(a + ra) - int(bc + rb))) for a in aopts
                          ], key=lambda x: x[2])[0]
        return best[0] + ra, best[1] + rb

    if bc == '?':
        bopts = []
        if ac > '0':
            bopts.append(chr(ord(ac) - 1))
        bopts.append(ac)
        if ac < '9':
            bopts.append(chr(ord(ac) + 1))
        best = sorted([
                          (ac, b, abs(int(ac + ra) - int(b + rb))) for b in bopts
                          ], key=lambda x: x[2])[0]
        return best[0] + ra, best[1] + rb
    if ac < bc:
        return ac + maxs(ar), bc + mins(br)
    if ac > bc:
        return ac + mins(ar), bc + maxs(br)


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
    # a, b = match(a, b)
    ap, bp = list(poss(a)), list(poss(b))
    p = []
    for x in ap:
        for y in bp:
            p.append((abs(int(x) - int(y)), x, y))
    _, a, b = sorted(p)[0]
    print "Case #%d:" % (t + 1), a, b
    s = 0
