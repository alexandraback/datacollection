t = input()
for case in xrange(1, t+1):
    s, pe = raw_input().split()
    s = int(s)
    pe = map(int, list(pe))
    num = pe[0]
    add = 0
    i = 1
    # 0 to s inclusive !!!
    while i <= s:
        if num >= i:
            num += pe[i]
            i += 1
        else:
            add += (i - num)
            num = i
            num += pe[i]
            i += 1
    print 'Case #%d: %d' % (case, add)
