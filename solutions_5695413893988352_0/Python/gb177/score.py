#!/usr/bin/python

#
# get the small one with brute-force
#
def N(): return tuple(map(int, raw_input().split()))

T = N()[0]
for c in range(T):
    coders, jammers = raw_input().split()
    # at most 10^6.
    pos = []
    for i, cc in enumerate(coders):
        if cc == '?':
            pos.append(i)

    CL = len(coders)
    for i, cc in enumerate(jammers):
        if cc == '?':
            pos.append(CL+i)

    d = "0123456789"
    #print pos, CL
    M = 10**len(pos)
    opt = []
    for i in range(M):
        cc = list(coders)
        ja = list(jammers)

        for j, p in enumerate(pos):
            dd = d[i/(10**j) % 10]
            if p < CL:
                cc[p] = dd
            else:
                ja[p-CL] = dd

        #print cc, ja
        cc = "".join(cc)
        ja = "".join(ja)
        cs = int(cc)
        js = int(ja)
        opt.append((abs(cs-js), cs, js, cc, ja))
            
    opt.sort()
    print "Case #%d: %s %s" % (c+1, opt[0][3], opt[0][4])

