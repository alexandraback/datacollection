import itertools
import time
from collections import defaultdict
import operator
#import collections
from collections import Counter

inputFileName = "test.in"
inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
#inputFileName = "B-small-attempt3.in"
#inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime

def countWord(str, w):
    lw = len(w)
    ls = len(str)
    cnt = 0
    for p in xrange(ls - lw + 1):
        good = True
        for i in xrange(lw):
            if str[i + p] != w[i]:
                good = False
                break
        if good:
            cnt += 1
    return cnt


def genAllWords(ks, S):
    result = [""]
    for i in xrange(S):
        new_res = []
        for x in ks:
            new_res.extend([oldWord + x for oldWord in result])
        result = new_res
    return result


def calcSingleTest(f):
    line = f.readline()
    K = int(line.split()[0])
    L = int(line.split()[1])
    S = int(line.split()[2])
    line = f.readline()
    ks = line
    if ks[-1] == '\n':
        ks = ks[:-1]
    line = f.readline()
    tgt = line
    if tgt[-1] == '\n':
        tgt = tgt[:-1]
    if max(K, L, S) > 8:
        return "AAAAAA"

    max_cnt = 0
    allWords = genAllWords(ks, S)
    wc = len(allWords)
    s = 0
    for str in allWords:
        cnt = countWord(str, tgt)
        if cnt > max_cnt:
            max_cnt = cnt
        s += cnt

    return (0.0 + wc * max_cnt - s) / wc

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            res = calcSingleTest(inpF)
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            print ' '
            outF.write('Case #{0}: {1}\n'.format(i, res))
            outF.flush()

print "Finished!!!! Total time = {0}".format((time.time() - startTime))

