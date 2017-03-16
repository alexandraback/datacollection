#! /usr/bin/python -tt

t = input()
f = open('out', 'w')
for case in range(1, t+1):
    aLine = raw_input()
    aLine = aLine.split()
    for e in aLine:
        e = int(e)
    n = int(aLine[0])
    s = int(aLine[1])
    p = int(aLine[2])
    t = [int(e) for e in aLine[3:]]
    print t
    ok_point = 3 * p - 2
    suprise_point = 3 * p - 4
    if p == 1:
        suprise_point = 1000000
    n_ok = n_suprise = 0
    for score in t:
        if score >= ok_point:
            n_ok += 1
        elif score >= suprise_point:
            n_suprise += 1
    ans = n_ok + min(n_suprise, s)
    f.write('Case #%d: %d\n' % (case, ans))
