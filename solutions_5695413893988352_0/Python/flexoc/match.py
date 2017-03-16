def toint(x):
    return int("".join(str(y) for y in x))

def rec(i, csmaller, c, j):
    c2, j2 = list(c), list(j)
    if i == len(c):
        return c2, j2
    if csmaller is True:
        if c[i] == -1:
            c2[i] = 9
        if j[i] == -1:
            j2[i] = 0
        return rec(i+1, csmaller, c2, j2)
    elif csmaller is False:
        if c[i] == -1:
            c2[i] = 0
        if j[i] == -1:
            j2[i] = 9
        return rec(i+1, csmaller, c2, j2)
    assert(csmaller is None)
    if c[i] != -1 and j[i] != -1:
        if c[i] == j[i]:
            return rec(i+1, None, c2, j2)
        elif c[i] < j[i]:
            return rec(i+1, True, c2, j2)
        else:
            return rec(i+1, False, c2, j2)
    if c[i] == -1 and j[i] == -1:
        c2[i] = 0
        j2[i] = 0
        a,b = rec(i+1, None, c2, j2)
        ai, bi = toint(a), toint(b)

        c2[i] = 1
        j2[i] = 0
        a2, b2 = rec(i+1, True, c2, j2)
        ai2, bi2 = toint(a2), toint(b2)
        if abs(ai2-bi2) < abs(ai-bi) or (abs(ai - bi) == abs(ai2-bi2) and (ai2 < ai or (ai2 == ai and bi2 < bi ) )):
            a = a2
            b = b2
            ai = ai2
            bi = bi2
    
        c2[i] = 0
        j2[i] = 1
        c2[i] = j[i] + 1
        a2,b2 = rec(i, False, c2, j2)
        ai2, bi2 = toint(a2), toint(b2)
        if abs(ai2-bi2) < abs(ai-bi) or (abs(ai -bi) == abs(ai2-bi2) and (ai2 < ai or (ai2 == ai and bi2 < bi ) )):
            a = a2
            b = b2
            ai = ai2
            bi = bi2
        return a, b

    if c[i] == -1 and j[i] != -1:
        c2[i] = j[i]
        a,b = rec(i+1, None, c2, j2)
        ai, bi = toint(a), toint(b)
        if j[i] > 0:
            c2[i] = j[i] - 1
            a2, b2 = rec(i+1, True, c2, j2)
            ai2, bi2 = toint(a2), toint(b2)
            if abs(ai2-bi2) < abs(ai-bi) or (abs(ai - bi) == abs(ai2-bi2) and (ai2 < ai or (ai2 == ai and bi2 < bi ) )):
                a = a2
                b = b2
                ai = ai2
                bi = bi2
        if j[i] < 9:
            c2[i] = j[i] + 1
            a2,b2 = rec(i, False, c2, j2)
            ai2, bi2 = toint(a2), toint(b2)
            if abs(ai2-bi2) < abs(ai-bi) or (abs(ai -bi) == abs(ai2-bi2) and (ai2 < ai or (ai2 == ai and bi2 < bi ) )):
                a = a2
                b = b2
                ai = ai2
                bi = bi2
        return a, b
    else:
        assert(c[i] != -1 and j[i] == -1)
        j2[i] = c[i]
        a,b = rec(i+1, None, c2, j2)
        ai, bi = toint(a), toint(b)
        if c[i] > 0:
            j2[i] = c[i] - 1
            a2, b2 = rec(i+1, False, c2, j2)
            ai2, bi2 = toint(a2), toint(b2)
            if abs(ai2-bi2) < abs(ai-bi) or (abs(ai -bi) == abs(ai2-bi2) and (ai2 < ai or (ai2 == ai and bi2 < bi ) )):
                a = a2
                b = b2
                ai = ai2
                bi = bi2
        if c[i] < 9:
            j2[i] = c[i] + 1
            a2,b2 = rec(i, True, c2, j2)
            ai2, bi2 = toint(a2), toint(b2)
            if abs(ai2-bi2) < abs(ai-bi) or (abs(ai -bi) == abs(ai2-bi2) and (ai2 < ai or bi2 < bi ) ):
                a = a2
                b = b2
                ai = ai2
                bi = bi2
        return a, b
        
T = int(input())
for t in range(T):
    cs, js = input().split()
    c = [-1 if x == '?' else int(x) for x in cs]
    j = [-1 if x == '?' else int(x) for x in js]

    ac, aj = rec(0, None, c, j)


    print("Case #%d: %s %s" % (t + 1, "".join(str(i) for i in ac), "".join(str(i) for i in aj)))
