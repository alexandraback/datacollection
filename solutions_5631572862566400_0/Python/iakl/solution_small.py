input_file = "C-small-attempt4.in"
output_file = "C-small-attempt4.out"

in_f = open(input_file)
T_read = False
N = -1
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if not T_read:
        T = int(sl)
        T_read = True
        continue
    if N == -1:
        N = int(sl)
    else:
        sl = sl.split(' ')
        tc = []
        for i in sl:
            tc.append(int(i))
        tcs.append(tc)
        N = -1
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x) + "\n")

def VerifyL(fm, l):
    N = len(fm)
    n = len(l)
    for i in range (0, n):
        kid = l[i]
        fr = fm[kid - 1]
        lft = (i - 1) % n
        rgt = (i + 1) % n
        if l[lft] != fr and l[rgt] != fr:
            return False
    return True

def SolveRec(fm, res, l):
    if len(l) == 0:
        return 0
    if len(l) > 1 and VerifyL(fm, l):
        res.append(len(l))
    n = len(l)
    next_fr = fm[l[n - 1] - 1]
    if next_fr not in l:
        nl = []
        nl.extend(l)
        nl.append(next_fr)
        SolveRec(fm, res, nl)
    fst_fr = fm[l[0] - 1]
    if fst_fr not in l:
        nl = [fst_fr]
        nl.extend(l)
        SolveRec(fm, res, nl)
    last_in = l[n - 1]
    N = len(fm)
    found = False
    for i in range(0, N):
        fr = fm[i]
        if fr == last_in and (i + 1) not in l:
            found = True
            nl = []
            nl.extend(l)
            nl.append(i + 1)
            SolveRec(fm, res, nl)
    for i in range(0, N):
        fr = fm[i]
        if fr == l[0] and (i + 1) not in l:
            nl = [i + 1]
            nl.extend(l)
            SolveRec(fm, res, nl)
            found = True
    if not found and len(l) > 1:
        if VerifyL(fm, l):
            res.append(len(l))
    

def SolveTestCase(tc):
    N = len(tc)
    if N < 2:
        return 0
    if N <= 3:
        return N
    res = []
    for i in range(0, N):
        SolveRec(tc, res, [i + 1])
    res = sorted(res)
    #print res
    #print res[len(res) - 1]
    return res[len(res) - 1]

#print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

