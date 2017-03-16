
ts = int(raw_input())

for t in range(ts):
    print "Case #{}:".format(t+1),

    j,p,s,k = [int(x) for x in raw_input().split(" ")]

    sol = []
    mjp = {}
    mjs = {}
    mps = {}
    for sv in range(1,s+1):
        for pv in range(1,p+1):
            for jv in range(1,j+1):
                    if (jv,pv) not in mjp: mjp[(jv,pv)] = 0
                    if (jv,sv) not in mjs: mjs[(jv,sv)] = 0
                    if (pv,sv) not in mps: mps[(pv,sv)] = 0
                    a = mjp[(jv,pv)]
                    b = mjs[(jv,sv)]
                    c = mps[(pv,sv)]
                    if a < k and \
                       b < k and \
                       c < k:
                        mjp[(jv,pv)] += 1
                        mjs[(jv,sv)] += 1
                        mps[(pv,sv)] += 1
                        sol += [[jv, pv, sv]]

    print len(sol)
    for x in sol: print " ".join(str(y) for y in x)
            
