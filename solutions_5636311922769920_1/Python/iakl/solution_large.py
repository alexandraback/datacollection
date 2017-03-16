input_file = "D-large.in"
output_file = "D-large.out"

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

def CalculatePosition(shifts, K):
    pos = 0
    for i in range (0, len(shifts) - 1):
        pos = (pos + shifts[i]) * K
    return pos + shifts[len(shifts) - 1]

def SolveTestCase(K, C, S):
    if C == 1 and S < K:
        return []
    if C == 1 and S >= K:
        r = []
        for i in range (0, K):
            r.append(i + 1)
        return r
    s = K / C
    if K % C != 0:
        s += 1
    if S < s:
        return []
    r = []
    shifts = []
    for i in range(0, K):
        shifts.append(i)
        if (i + 1) % C == 0 or i == K - 1:
            print shifts
            pos = CalculatePosition(shifts, K)
            r.append(pos + 1)
            shifts = []
    return sorted(r)            

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i][0], tcs[i][1], tcs[i][2])
    OutputTestCase(i + 1, r)

out_f.close()

