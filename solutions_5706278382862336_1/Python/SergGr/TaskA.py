from fractions import gcd

#inputFileName = "test.in"
#inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
#inputFileName = "A-small-attempt2.in"
#inputFileName = "A-small-attempt3.in"
inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def log2Exact(x):
    p = 1
    for i in xrange(0, 50):
        if x == p:
            return i
        if x < p:
            return -1
        p *= 2
    return -1


def log2(x):
    p = 1
    for i in xrange(0, 50):
        if x == p:
            return i
        if x < p:
            return i - 1
        p *= 2
    return -1


def calcSingleTest(f):
    line = f.readline()
    p0 = int(line.split('/')[0])
    q0 = int(line.split('/')[1])
    g = gcd(p0, q0)
    p = p0 / g
    q = q0 / g
    print "{0}/{1} {2} = {3}/{4}".format(p0, q0, g, p, q)
    q2 = log2Exact(q)
    if p > q:
        return 'impossible'
    if q2 == -1:
        return 'impossible'
    if q2 > 40:
        return 'impossible'
    p2 = log2(p)
    return max(q2 - p2, 1)


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




