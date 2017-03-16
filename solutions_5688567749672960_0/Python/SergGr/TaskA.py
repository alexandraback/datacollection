inputFileName = "test.in"
inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
#inputFileName = "A-small-attempt2.in"
#inputFileName = "A-small-attempt3.in"
#inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def findBest(x, allowReversed=True):
    if x < 20:
        return x
    digits = str(x)
    l = len(digits)
    p1 = int(digits[0:l / 2][::-1])
    p2 = int(digits[l / 2:l])

    return 1 + p1 + p2 + findBest(10 ** (l - 1) - 1)


def calcSingleTest(f):
    line = f.readline()
    N = int(line)

    return findBest(N)


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




