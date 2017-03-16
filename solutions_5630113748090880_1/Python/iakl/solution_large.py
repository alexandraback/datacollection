input_file = "B-large.in"
output_file = "B-large.out"

in_f = open(input_file)
T_read = False
N = -1
tc = []
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if not T_read:
        T = int(sl)
        T_read = True
        continue
    if N < 0:
        N = int(sl)
        continue
    row = []
    sl = sl.split(' ')
    for i in range(0, N):
        row.append(int(sl[i]))
    tc.append(row)
    if N >= 0 and len(tc) == (2 * N - 1):
        N = -1
        tcs.append(tc)
        tc = []
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, r):
    wr = "Case #" + str(tcn) + ":"
    for h in r:
        wr = wr + ' ' + str(h)
    wr = wr + "\n"
    out_f.write(wr)


def SolveTestCase(tc):
    if len(tc) == 0:
        return []
    N = len(tc[0])
    mn = 0
    mx = 0
    count = 0
    for r in tc:
        for h in r:
            if count == 0:
                mn = h
                mx = h
            else:
                if h < mn:
                    mn = h
                if h > mx:
                    mx = h
            count += 1
    l = [0] * (mx - mn + 1)
    
    for r in tc:
        for h in r:
            l[h - mn] += 1
    r = []
    n = len(l)
    for i in range(0, n):
        if (l[i] % 2) == 1:
            r.append(i + mn)
    return sorted(r)

#print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    #print r
    OutputTestCase(i + 1, r)

out_f.close()

