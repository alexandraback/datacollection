inputFileName = "test.in"
inputFileName = "A-small-attempt0.in"
# inputFileName = "A-small-attempt1.in"
# inputFileName = "A-small-attempt2.in"
# inputFileName = "A-small-attempt3.in"
# inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def calcSingleTest(f):
    line = f.readline()
    s = line.translate(None, '\r\n')
    res = ''
    res += s[0]
    for c in s[1:]:
        if c >= res[0]:
            res = c + res
        else:
            res = res + c
    return res


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))
