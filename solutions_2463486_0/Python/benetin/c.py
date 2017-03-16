T = 0
P10 = [pow(10, x) for x in xrange(103)]
P10_9 = [x*9 for x in P10]
ans = []
F = 0
F1 = 0
C1 = 0

def test():
    sf = str(F*F)
    return sf == sf[::-1]

def play(a):
    global pt, ans, F, F1, C1
    # set a and T-1-a.
    if a < T-1-a:
        F -= (P10[a] + P10[T-1-a])
    else:
        F -= P10[a]
    F1 -= P10[a]
    for d in xrange(10):
        if a < T-1-a:
            F += (P10[a] + P10[T-1-a])
        else:
            F += P10[a]
        F1 += P10[a]
        if a == 0 and d == 0:
            continue
        if d > 2 and T > 1:
            continue
        if d == 2:
            if a != 0 and a != T-1-a:
                continue
        if d == 1 and C1 > 4:
            continue
        if a + 1 >= T-1-a:
            if test():
                ans.append(F)
            continue
        Fh = F / P10[T-1-a]
        s1=str(Fh*Fh)
        s2=str((Fh+1)*(Fh+1))
        s3 = str((F1+P10[a+1])*(F1+P10[a+1]))[::-1]
        i1 = int(s1[:a+1])
        i2 = int(s2[:a+1])
        i3 = int(s3[:a+1])
        if len(s1) == len(s2):
            if i3 < i1 or i3 > i2:
                continue
        else:
            if i3 < i2 and i3 > i1:
                continue
        if d > 0:
            C1 += 1
        play(a+1)
        if d > 0:
            C1 -= 1
    if a < T-1-a:
        F -= (P10_9[a] + P10_9[T-1-a])
    else:
        F -= P10_9[a]
    F1 -= P10_9[a]

for t in xrange(1, 51):
    F = 0
    F1 = 0
    C1 = 0
    T = t
    play(0)

T = int(raw_input())

for z in xrange(T):
    L = raw_input().split()
    A, B = long(L[0]), long(L[1])
    ret = 0
    for x in ans:
        if x*x >= A and x*x <= B:
            ret += 1
    print 'Case #%s: %s' % (z+1, ret)
