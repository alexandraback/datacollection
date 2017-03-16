INFTY = 10000000

def distance(val, l):
    dist = 0
    for (n, tl) in l:
        if tl == val[1]:
            return (dist, min(val[0], n))
        dist += n
    return (INFTY, 0)

def factory(As, Bs):
    N = 0
    while As and Bs:
        (dA, wA) = distance(As[0], Bs)
        (dB, wB) = distance(Bs[0], As)
        scoreA = float(wA) / (dA + wA)
        scoreB = float(wB) / (dB + wB)
        if dA == 0:
            n = min(As[0][0], Bs[0][0])
            N += n
            As[0] = (As[0][0] - n, As[0][1])
            Bs[0] = (Bs[0][0] - n, Bs[0][1])
            if As[0][0] == 0:
                As = As[1:]
            if Bs[0][0] == 0:
                Bs = Bs[1:]
        elif dA == INFTY and dB == INFTY:
            return N
        elif scoreB > scoreA:
            As = As[1:]
        elif scoreA > scoreB:
            Bs = Bs[1:]
        elif dA == dB:
            return max(factory(list(As[1:]), list(Bs)),
                       factory(list(As), list(Bs[1:])))
    return N

def group(l):
    res = []
    for i in xrange(0, len(l), 2):
        res.append((l[i], l[i+1]))
    return res

if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        N, M = map(int, raw_input().split(' '))
        As = map(int, raw_input().split(' '))
        Bs = map(int, raw_input().split(' '))
        print "Case #%d: %d" % (i+1, factory(group(As), group(Bs)))
