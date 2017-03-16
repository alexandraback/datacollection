input_file = "C-small-attempt0.in"
output_file = "C-small-attempt0.out"

in_f = open(input_file)
T = -1
N = -1
tcs = []
tc = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if T == -1:
        T = int(sl)
        continue
    if N == -1:
        N = int(sl)
    else:
        sl = sl.split(' ')
        tc.append(sl)
        if len(tc) == N:
            tcs.append(tc)
            N = -1
            tc = []
        
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x) + "\n")

def Reduce(tc, N, used, do1, do2, ors):
    fc = 0
    for i in range(0, N):
        if not used[i] and tc[i][0] in do1 and tc[i][1] in do2:
            fc += 1
            used[i] = True
            do1[tc[i][0]] += 1
            do2[tc[i][1]] += 1
            ors.append(tc[i])
    return fc

def PickNext(tc, N, used, do1, do2):
    for i in range(0, N):
        if not used[i] and (tc[i][0] not in do1) and (tc[i][1] not in do2):
            return i
    for i in range(0, N):
        if not used[i]:
            return i

def SolveTestCase(tc):
    N = len(tc)
    used = [False] * N
    d1 = dict()
    d2 = dict()
    for i in range(0, N):
        if not tc[i][0] in d1:
            d1[tc[i][0]] = 0
        d1[tc[i][0]] += 1
        if not tc[i][1] in d2:
            d2[tc[i][1]] = 0
        d2[tc[i][1]] += 1
    fc = 0
    ors = []
    do1 = dict()
    do2 = dict()
    for i in range(0, N):
        if d1[tc[i][0]] == 1 or d2[tc[i][1]] == 1:
            used[i] = True
            if not tc[i][0] in do1:
                do1[tc[i][0]] = 0
            do1[tc[i][0]] += 1
            if not tc[i][01] in do2:
                do2[tc[i][1]] = 0
            do2[tc[i][1]] += 1
            ors.append(tc[i])
    fnd = -1
    while fnd != 0:
        fnd = Reduce(tc, N, used, do1, do2, ors)
        fc += fnd
    if len(ors) == N:
        return fc
    while len(ors) < N:
        nxt = PickNext(tc, N, used, do1, do2)
        used[nxt] = True
        ors.append(tc[nxt])
        if not tc[nxt][0] in do1:
            do1[tc[nxt][0]] = 0
        do1[tc[nxt][0]] += 0
        if not tc[nxt][1] in do2:
            do2[tc[nxt][1]] = 0
        do2[tc[nxt][1]] += 1
        fnd = -1
        while fnd != 0:
            fnd = Reduce(tc, N, used, do1, do2, ors)
            fc += fnd
    print fc
    return fc
    

#print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

