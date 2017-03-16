import itertools
import math

input_file = "B-small-attempt0.in"
output_file = "B-small-attempt0.out"

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
    CJ = sl.split(' ')
    tcs.append([CJ[0], CJ[1]])
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x[0]) + ' ' + str(x[1]) + "\n")

def Match(x, y):
    for i in range(0, len(x)):
        if x[i] == '?':
            continue
        if x[i] != y[i]:
            return False
    return True

def ToDec(y):
    l = len(y)
    r = 0
    mp = 1
    for i in range(0, l):
        r += int(y[l - i - 1]) * mp
        mp = mp * 10
    return r

def CalcDiff(x1, x2):
    x1d = ToDec(x1)
    x2d = ToDec(x2)
    return [abs(x1d - x2d), x1d, x2d]

def ToStr(dx, R):
    r = ""
    for i in range(0, R):
        r = str(dx % 10) + r
        dx = int(dx / 10)
    return r

def SolveTestCase(tc):
    C = tc[0]
    J = tc[1]
    R = len(C)
    inp = "0123456789"
    cA = itertools.product(inp, repeat = R)
    cB = itertools.product(inp, repeat = R)
    A = []
    B = []
    for a in cA:
        if Match(C, a):
            A.append(a)
    for b in cB:
        if Match(J, b):
            B.append(b)
    res = [999, 999, 999]
    for a in A:
        for b in B:
            df = CalcDiff(a, b)
            if df[0] < res[0]:
                res = df
            elif res[0] == df[0]:
                if df[1] < res[1]:
                    res = df
                elif res[1] == df[1] and df[2] < res[2]:
                    res = df
    res = [ToStr(res[1], R), ToStr(res[2], R)]
    return res
                
    

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

