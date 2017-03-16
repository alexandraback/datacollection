input_file = "D-small-attempt0.in"
output_file = "D-small-attempt0.out"

in_f = open(input_file)
T_read = False
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if not T_read:
        T = int(sl)
        T_read = True
        continue
    KCS = l.split(' ')
    tcs.append([int(KCS[0]), int(KCS[1]), int(KCS[2])])
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, r):
    x = ""
    if len(r) == 0:
        x = " IMPOSSIBLE"
    else:
        for p in r:
            x = x + ' ' + str(p)
    out_f.write("Case #" + str(tcn) + ":" + x + "\n")

#Note: works only for a small dataset
def SolveTestCase(K, C, S):
    # note: eliminates the large dataset cases
    if S < K:
        return []
    else:
        r = []
        for i in range(0, K):
            r.append(i + 1)
        return r

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i][0], tcs[i][1], tcs[i][2])
    OutputTestCase(i + 1, r)

out_f.close()

