#inputFileName = "test.in"
#inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
inputFileName = "B-small-attempt3.in"
#inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"


def calcNLevel(N):
    if N == 1:
        return (1,1,0)
    i = 0
    while 2 * (i ** 2) - i < N:
        i += 1
    return (i, 2 * ((i-1) ** 2) - i-1 - N, 2 * (i ** 2) - i - N)

print str(calcNLevel(4))


def binSum(n, k):
    s = 0
    c = 1
    for i in range(0, k + 1):
        s += c
        c *= (n - i)
        c /= (i + 1)
    return s


def binP(n, k):
    s = binSum(n, k)
    p2 = float(s) / 2 ** n
    return p2


def calcSingleTest(f):
    line = f.readline()
    N = int(line.split()[0])
    X = int(line.split()[1])
    Y = int(line.split()[2])
    return calcSingleTest2(N, abs(X), Y)

    #N = 10
    #X = 3
    #Y = 1
    #X = 4
    #Y = 0


def calcSingleTest2(N, X, Y):
    if X == 0 and Y == 0:
        return 1 if N > 0 else 0
    if N == 1:
        return 0

    (nLevel, nRest, nRest2) = calcNLevel(N)
    #print "N={0}, nLevel={1}, nRest={2}, nRest2={3}".format(N, nLevel, nRest, nRest2)
    pLevel = (abs(X) + Y) / 2 + 1
    pPos = Y
    #print "X={0}, Y={1}, pLevel={2}, pPos={3}".format(X, Y, pLevel, pPos)
    if pLevel < nLevel:
        return 1
    if pLevel > nLevel:
        return 0

    if nRest2 == 0:
        return 1

    if pPos == 2 * (pLevel - 1):
        return 1 if nRest2 == 0 else 0
    if nRest <= nLevel:
    #        s = binSum(nRest, pPos)
    #        p2 = 2 ** nRest
    #        p = 1 - float(s) / p2
    #        print "s={0}, 2** = {1}, p = {2}".format(s, p2, p)
    #        return p
        return 1 - binP(nRest, pPos)
    else:
        levelRest = nLevel - pPos - 1
        p = binP(nRest2 - 1, levelRest)
        #print "p={0}, rest = {1}, levelRest = {2}".format(p, nRest2 - 1, levelRest)
        return p
    return -1


#print binSum(3, 4)
#for N in xrange(2, 100):
#    r = int((N + 2) ** 0.5)
#    r2 = r * r - 3
#    print "N={0}, r={1}, r2={2}".format(N, r, r2)

for N in xrange(2, 21):
    print "------------------------------------------"
    (nLevel, nRest, nRest2) = calcNLevel(N)
    #print "N = " + str(N)
    print "N={0}, nLevel={1}, nRest={2}, nRest2={3}".format(N, nLevel, nRest, nRest2)
    s = 0
    s2 = 0
    for Y in xrange(0, nLevel + 2):
        X = 2 * (nLevel - 1) - Y
        r = calcSingleTest2(N, X, Y)
        s += r
        if X > 0:
            s2 += 2 * r
        else:
            s2 += r
            #print "N={0}, X={1}, Y={2}, r={3}".format(N, X, Y, r)
        print "X={1}, Y={2}, r={3}".format(N, X, Y, r)
    print "s={0}, s2 = {1}, nRest = {2}".format(s, s2, nRest)
    if nRest != s2:
        print "AAAAAAAAAAAAAAAAA"

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




