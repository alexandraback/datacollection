#!/usr/bin/python3.4

q1 = 1, 0, 0, 0
qI = 0, 1, 0, 0
qJ = 0, 0, 1, 0
qK = 0, 0, 0, 1

def fromChar(c):
    if (c == '1'): return q1
    elif (c == 'i'): return qI
    elif (c == 'j'): return qJ
    else: return qK

def mul(a, b):
    w1, x1, y1, z1 = a
    w2, x2, y2, z2 = b
    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
    y = w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2
    z = w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2
    return w, x, y, z

def mulc(quat, c):
    return mul(quat, fromChar(c))

T = int(input())
for case in range(1, T + 1):
    L, X = map(int, input().split())
    inp = input()
    LX = 1

    impPrd = q1
    for c in inp:
        impPrd = mulc(impPrd, c)

    if (X > 12):
        inp = inp * 12
        LX = L * 12;
    else:
        inp = inp * X
        LX = L * X;

    foundI = False;
    foundJ = False;

    pref = q1 
    i = 0
    while (not foundI and (i < LX)):
        pref = mulc(pref, inp[i])
        if (pref == qI):
            foundI = True
            pref = q1
        i += 1

    while (not foundJ and (i < LX)):
        pref = mulc(pref, inp[i])
        if (pref == qJ):
            foundJ = True
            pref = q1
        i += 1

    while (i < LX):
        pref = mulc(pref, inp[i])
        i += 1

    if (X <= 12):
        if (foundI and foundJ and (pref == qK)):
            print("Case #" + str(case) + ": YES")
        else:
            print("Case #" + str(case) + ": NO")
    else:
        if (foundI and foundJ):
            for j in range(X % 4):
                pref = mul(pref, impPrd)
            if (pref == qK):
                print("Case #" + str(case) + ": YES")
            else:
                print("Case #" + str(case) + ": NO")                
        else:
            print("Case #" + str(case) + ": NO")
