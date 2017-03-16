cases = input()
for case in range(cases):
    c = input()
    al = al_org = sorted(map(float, raw_input().split()))
    bl = sorted(map(float, raw_input().split()))

    dw = 0
    for b in reversed(bl):
        if al[-1] > b:
            al = al[:-1]
            dw += 1
        else:
            al = al[1:]

    w = 0
    for a in reversed(al_org):
        if a > bl[-1]:
            bl = bl[1:]
            w += 1
        else:
            bl = bl[:-1]

    print "Case #%d: %d %d" % (case + 1, dw, w)
