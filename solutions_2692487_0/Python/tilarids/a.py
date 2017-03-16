def solve(a, motes):
    if 1 == a:
        return len(motes)
    # print a, motes
    while motes and a>motes[0]:
        a+= motes[0]
        del motes[0]
    if motes:
        if 1 == len(motes):
            return 1
        else:
            # import pdb; pdb.set_trace()

            next = motes[0]
            i = 1
            aa = a+a-1
            while aa <= next:
                aa += aa - 1
                i += 1
            z = solve(aa + next, motes[1:]) + i
            zz = solve(a, motes[1:]) + 1
            return min(z, zz)
    else:
        return 0

if __name__ == '__main__':
    import sys
    f = sys.stdin
    # f = open('a.in')
    lines = [x.strip() for x in f.readlines() if x.strip()][1:]
    for x in xrange(len(lines) / 2):
        a,n = map(int, lines[x*2].split())
        motes = map(int, lines[2*x+1].split())
        motes.sort()
        print "Case #%s: %s" % (x+1, solve(a, motes))
