def tot_area(r, n):
    return (2*n + 2*r - 1) * n

fi = open('A-large.in', 'r')
fo = open('A-large.out', 'w')

T = int(fi.readline())
for case_i in range(T):
    line = fi.readline().split()
    r = int(line[0])
    t = int(line[1])

    # Small Version
    '''
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
    '''

    # Large Version
    l_range = 1
    r_range = 2147483647
    ans = -1
    while l_range < r_range:
        mid = (l_range + r_range) // 2
        if tot_area(r, mid) <= t and tot_area(r, mid + 1) > t:
            ans = mid
            break
        elif tot_area(r, mid) < t:
            l_range = mid
        else:
            r_range = mid
    if ans == -1:
        ans = r_range

    fo.write('Case #%d: %d\n' % (case_i + 1, ans))

fi.close()
fo.close()
