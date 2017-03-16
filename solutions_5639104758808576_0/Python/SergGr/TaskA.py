#inputFileName = "test.in"
inputFileName = "A-small-attempt0.in"
#inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def calcSingleTest(f):
    line = f.readline()
    maxS = int(line.split()[0]) + 1
    s = map(int, line.split()[1])
    add = 0
    sum = 0
    for i in xrange(0, maxS):
        if s[i] == 0:
            continue
        if sum < i:
            add += i - sum
            sum = i
        sum += s[i]

    return add


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




