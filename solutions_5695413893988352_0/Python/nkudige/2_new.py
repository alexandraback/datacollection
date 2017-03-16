def isPossible(item, x):
    for (i, ch) in enumerate(x):
        if ch != '?' and ch != item[i]:
            return False

    return True

def getAllPossible(x):
    allPossible = []

    gen = ["%03d" % i for i in xrange(1000)]

    for item in gen:
        if isPossible(item, x):
            allPossible.append(item)

    return allPossible

def getSol(C, J):
    C, J = list(C), list(J)

    mindiff = 100000
    sol = (0, 0)

    C_poss = map(int, getAllPossible(C))
    J_poss = map(int, getAllPossible(J))

    for c in C_poss:
        for j in J_poss:
            if abs(c - j) < mindiff:
                mindiff = abs(c - j)
                sol = (c, j)

    return sol

T = int(raw_input())

for t in xrange(1, T+1):
    (C, J) = raw_input().split()
    l = len(C)
    if len(C) != 3:
        C = '0'*(3-len(C)) + C
    if len(J) != 3:
        J = '0'*(3-len(J)) + J
    sol = getSol(C, J)

    if l == 1:
        print 'Case #%d: %01d %01d' % (t, sol[0], sol[1])
    if l == 2:
        print 'Case #%d: %02d %02d' % (t, sol[0], sol[1])
    if l == 3:
        print 'Case #%d: %03d %03d' % (t, sol[0], sol[1])