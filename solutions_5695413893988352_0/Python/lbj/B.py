t = int(input())
cache = {}
def optimize(ls,rs,lx,rx):
    global cache
    if not lx or not rx:
        return ls,rs
    k = '%s-%s-%s-%s' % (ls,rs,lx,rx)
    if k in cache:
        ls,rs = cache[k]
        return ls,rs
    a = lx[0]
    b = rx[0]
    if '?' not in (a,b):
        ls += a
        rs += b
        return optimize(ls, rs, lx[1:], rx[1:])
    if ls < rs:
        if a == '?':
            ls += '9'
        else:
            ls += a
        if b == '?':
            rs += '0'
        else:
            rs += b
        return optimize(ls, rs, lx[1:], rx[1:])
    elif ls > rs:
        if a == '?':
            ls += '0'
        else:
            ls += a
        if b == '?':
            rs += '9'
        else:
            rs += b
        return optimize(ls, rs, lx[1:], rx[1:])
    else: # ls == rs, compare at this digit
        candidates = []
        if a == '?':
            if b == '?':
                candidates.append(('0','0'))
                candidates.append(('0','1'))
                candidates.append(('1','0'))
            else:
                cnd = b
                if b != '0':
                    candidates.append((chr(ord(b) - 1), b))
                candidates.append((b,b))
                if b != '9':
                    candidates.append((chr(ord(b) + 1), b))
        elif b == '?':
            if a != '0':
                candidates.append((a,chr(ord(a) - 1)))
            candidates.append((a,a))
            if a != '9':
                candidates.append((a,chr(ord(a) + 1)))
        else:
            assert False, "Should never happen"
        bestl,bestr = None,None
        bestv = float('inf')
        for ca,cb in candidates:
            cl,cr = optimize(ls + ca, rs + cb, lx[1:], rx[1:])
            v = abs(int(cl) - int(cr))
            if v < bestv:
                bestv = v
                bestl, bestr = cl, cr
        ls,rs = bestl, bestr
    cache[k] = (ls,rs)
    return ls,rs
for cn in range(t):
    l,r = raw_input().split()
    ls, rs = optimize('','',l,r)
    print("Case #%d: %s %s" % (cn + 1, ls, rs))
