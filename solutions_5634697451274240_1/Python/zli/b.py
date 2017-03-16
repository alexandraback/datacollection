def xl(l):
    return xrange(len(l))

for case in range(1, input()+1):
    print "Case #%s:" % (case),
    S = raw_input()
    regions = 1
    last = S[0]
    for c in S:
        if last != c:
            regions += 1
            last = c
    print regions - (S[-1] == '+')
