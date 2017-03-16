with open('D-large.in') as f:
    data = [line.rstrip() for line in f]
i = 1
ncase = 1
while i < len(data):
    print "Case #%d:" % ncase,
    i += 1
    n = [float(j) for j in data[i].split()]
    k = [float(j) for j in data[i+1].split()]
    i += 2
    sn = sorted(n)
    sk = sorted(k)
    dns, dne = 0, len(n) - 1
    dks, dke = 0, len(n) - 1
    dw = 0
    while dke > -1:
        if sn[dne] < sk[dke]:
            dns += 1
        else:
            dne -= 1
            dw += 1
        dke -= 1
    ons, one = 0, len(n) - 1
    oks, oke = 0, len(n) - 1
    ow = 0
    while one > -1:
        if sn[one] < sk[oke]:
            oke -= 1
        else:
            oks += 1
            ow += 1
        one -= 1
    print dw, ow
    ncase += 1