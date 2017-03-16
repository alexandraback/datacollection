f = open("in.txt", "r")
fOut = open("out.txt", "w")
t = int(f.readline())
for i in range(1, t+1):
    n = int(f.readline())
    naomi = [float(x) for x in sorted(f.readline().split())]
    ken = [float(x) for x in sorted(f.readline().split())]
    pn = 0
    pk = 0
    dWarR = 0
    for k in range(0, n):
        if naomi[pn] > ken[pk]:
            dWarR += 1
            pk += 1
        pn += 1

    pn = 0
    pk = 0
    warR = 0
    for k in range(0, n):
        if ken[pk] > naomi[pn]:
            warR += 1
            pn += 1
        pk += 1
    warR = n - warR
    fOut.write("Case #{:d}: {:d} {:d}\n".format(i, dWarR, warR))