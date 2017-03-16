input_file = "B-small-attempt0.in"
output_file = "B-small-attempt0.out"

import math
import copy

in_f = open(input_file)
T = -1
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if T == -1:
        T = int(sl)
        continue
    BM = sl.split(' ')
    tcs.append([int(BM[0]), int(BM[1])])
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    if len(x) == 0:
        res = "IMPOSSIBLE"
    else:
        res = "POSSIBLE" + '\n'
        B = len(x[0])
        for i in range(0, B):
            for j in range(0, B):
                res += str(x[i][j])
            if i < B - 1:
                res += '\n'
    out_f.write("Case #" + str(tcn) + ": " + res + "\n")

def CheckWay(m, w, B):
    mw = [0]
    for i in range(0, len(w)):
        if w[i] == 1:
            mw.append(i + 1)
    mw.append(B - 1)
    N = len(mw)
    for i in range(0, N - 1):
        if m[mw[i]][mw[i + 1]] == 0:
            return False
    return True

def Check(m, B):
    r = 0
    mxws = int(math.pow(2, B - 2))
    for nm in range(0, mxws):
        w = [0] * (B - 2)
        s = nm + 0
        for pos in range(0, B - 2):
            w[pos] = s % 2
            s = s / 2
        if CheckWay(m, w, B):
            r += 1
    return r
        

def SolveTestCase(tc):
    B = tc[0]
    M = tc[1]
    mx = int(math.pow(2, B - 2))
    if M > mx:
        return []
    if B == 2 and M == 1:
        return [[0, 1], [0, 0]]
    mcs = int(math.pow(2, B * (B - 1) / 2))
    for nm in range (1, mcs + 1):
        m = [[0 for x in range(B)] for y in range(B)]  
        s = nm + 0
        for i in range (0, B):
            for j in range(i + 1, B):
                m[i][j] = s % 2
                s = s / 2
        r = Check(m, B)
        if r == M:
            return m
                    
print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

