#inputFileName = "test.in"
#inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def calcSingleTest(f):
    line = f.readline()
    size = int(line.split()[0])
    count = int(line.split()[0])
    line = f.readline()
    others = sorted(map(int, line.split()))
    print size
    print others
    if size == 1:
        return len(others)
    max = others[-1]
    results = []
    add = 0
    l = len(others)
    others.append(10**20) #
    for pos in xrange(len(others)):
        o = others[pos]
        if size > max:
            results.append(add)
            break
        if size > o:
            size += o
            continue
        results.append(add + l - pos)
        while size <= o:
            size = 2 * size - 1
            add += 1
        size += o
    print "res:"
    print results
    results = sorted(results)
    print results
    return results[0]

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




