fi = open('A-small-attempt0.in', 'r')
fo = open('a.out', 'w')

T = int(fi.readline())
for case_i in range(T):
    line = fi.readline().split()
    r = int(line[0])
    t = int(line[1])

    # Small Version
    tr = r + 1
    tot = tr * tr - (tr - 1) * (tr - 1)
    ans = 1
    
    while tot < t:
        tr += 2
        cir = tr * tr - (tr - 1) * (tr - 1)
        if tot + cir > t:
            break
        tot += cir
        ans += 1

    fo.write('Case #%d: %d\n' % (case_i + 1, ans))

fi.close()
fo.close()
