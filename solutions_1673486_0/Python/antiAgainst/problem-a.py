#!/usr/bin/python2

def calcProdP(ps):
    prodp = [1]
    for p in ps:
        prodp.append(p * prodp[len(prodp) - 1])
    return prodp

def calcKeepType(a, b, prodp):
    return (b - a + 1) * prodp + (2 * b - a + 2) * (1 - prodp)

def calcReturnRetype(b):
    return b + 2

def calcBackRetype(a, b, prodp):
    backp = []
    for bks in range(1, a):
        tmpp = prodp[a - bks]
        tmp = (2 * bks + b - a + 1) * tmpp + (2 * bks + 2 * b - a + 2) * (1 - tmpp)
        backp.append(tmp)
    # backspace - remove all typed
    backp.append(a + b + 1)
    return min(backp)

if __name__ == "__main__":

    f = open('A-small-attempt0.in')
    tc = int(f.readline().strip())

    for t in range(tc):
        print "Case #%d: " % (t + 1),

        a, b = f.readline().split()
        a = int(a)
        b = int(b)
        ps = f.readline().split()
        ps = [float(p) for p in ps]

        prodp = calcProdP(ps)
        keepType = calcKeepType(a, b, prodp[a])
        retRetype = calcReturnRetype(b)
        backRetype = calcBackRetype(a, b, prodp)

        ans = min(keepType, retRetype, backRetype)
        print "%.6f" % ans
