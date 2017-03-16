motes = None
MIN = None
def solve(cur, a, st):
    global MIN
    if cur > MIN:
        return 1000000
    if 1 == a:
        return cur + len(motes) - st
    # print a, motes
    while st<len(motes) and a>motes[st]:
        a+= motes[st]
        st += 1
    if st<len(motes):
        if 1 == len(motes) - st:
            MIN = min(cur + 1, MIN)
            return cur + 1
        else:
            next = motes[st]
            i = 1
            aa = a+a-1
            while aa <= next:
                aa += aa - 1
                i += 1
            if i > len(motes) - st:
                z = 1000000
            else:
                z = solve(cur + i, aa + next, st + 1)
                MIN = min(z, MIN)
            zz = solve(cur + 1, a, st + 1)
            MIN=min(zz, MIN)
            return min(z, zz)
    else:
        MIN = min(cur, MIN)
        return cur

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(1000000)
    f = sys.stdin
    # f = open('a.in')
    lines = [x.strip() for x in f.readlines() if x.strip()][1:]
    for x in xrange(len(lines) / 2):
        a,n = map(int, lines[x*2].split())
        motes = map(int, lines[2*x+1].split())
        motes.sort()
        MIN = len(motes)
        print "Case #%s: %s" % (x+1, solve(0, a, 0))
