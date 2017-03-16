def solve(a, b):
    dif = 0
    for i in xrange(n):
        if a[i] != '?' and b[i] != '?':
            dif += 10**(n-i-1) * (int(a[i]) - int(b[i]))
    for i in xrange(n):
        if a[i] != '?' and b[i] != '?': continue
        p = 10**(n-i-1)
        dif = min((dif+p*(r-s) for r in xrange(10) for s in xrange(10)
                  if ((a[i] == '?' or str(r) == a[i]) and
                      (b[i] == '?' or str(s) == b[i]))),
                  key=abs)
    return abs(dif)
                    
def pos(a, b, ma, mb, ans):
    a, b = a[:], b[:]
    dif = 0
    for i in xrange(n):
        if a[i] != '?' and b[i] != '?':
            dif += 10**(n-i-1) * (int(a[i]) - int(b[i]))
    for i in xrange(n):
        if a[i] != '?' and b[i] != '?': continue
        p = 10**(n-i-1)
        best = None
        for r in xrange(10):
            for s in xrange(10):
                if ((a[i] == '?' or str(r) == a[i]) and
                    (b[i] == '?' or str(s) == b[i])):
                    x = int(''.join(a[:i] + [str(r)] + a[i+1:]).replace('?', '0'))
                    y = int(''.join(b[:i] + [str(s)] + b[i+1:]).replace('?', '0'))
                    if x <= ma and y <= mb:
                        if (best is None) or abs(dif+p*(r-s)) < abs(best[0]):
                            best = (dif+p*(r-s), r, s)
        if best is None: return False
        a[i], b[i] = str(best[1]), str(best[2])
        dif = best[0]
    return abs(dif) <= ans

T = input()
for t in xrange(1, T+1):
    print 'Case #{}:'.format(t),
    a, b = map(list,raw_input().split())
    n = len(a)
    ans = solve(a, b)
    ax, bx = 2**20 - 1, 2**20 - 1
    for bi in xrange(19, -1, -1):
        if pos(a, b, ax - 2**bi, bx, ans):
            ax -= 2**bi
    for bi in xrange(19, -1, -1):
        if pos(a, b, ax, bx - 2**bi, ans):
            bx -= 2**bi

    print str(ax).zfill(n), str(bx).zfill(n)
    

