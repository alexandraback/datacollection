import itertools
import time
from collections import defaultdict
import operator
#import collections
from collections import Counter

#inputFileName = "test.in"
#inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
#inputFileName = "B-small-attempt3.in"
inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime

MOD = 1000000007

class ValidTrain:
    def __init__(self, t):
        self.start = t[0]
        self.end = t[-1]
        self.sames = dict()


def fact(N):
    res = 1
    for x in xrange(1, N + 1):
        res *= x
        res %= MOD
    return res


def shrinkSame(t):
    res = ''
    res += t[0]
    c = t[0]
    for x in xrange(1, len(t)):
        if t[x] == c:
            continue
        c = t[x]
        res += t[x]
    return res


def testGood(s):
    cur = s[0]
    used = set()
    used.add(cur)
    for ch in s:
        if ch == cur:
            continue
        if ch in used:
            return False
        used.add(ch)
        cur = ch
    return True


def calcSingleTest2(ts0):
    ts = []
    for t in ts0:
        ts.append(shrinkSame(t))
    cnt = 0
    for p in itertools.permutations(ts):
        s = ''
        for t in p:
            s += t
        if testGood(s):
            cnt += 1

    return cnt


def calcSingleTest(f):
    line = f.readline()
    n = int(line)
    line = f.readline()
    ts = line.split()
    starts = dict()
    ends = dict()
    same = defaultdict(int)
    middles = dict()
    dif = list()
    print ts
    #r2 = calcSingleTest2(ts)

    for t in ts:
        s = t[0]
        e = t[-1]
        l = len(t)
        if s == e:
            for i in xrange(1, l - 1):
                if t[i] != s:
                    return 0
            if s in same:
                same[s] += 1
            else:
                same[s] = 1
        else:
            if not testGood(t):
                return 0
            dif.append(t)
            if s in starts:
                return 0
            starts[s] = t
            if e in ends:
                return 0
            ends[e] = t
            for i in xrange(1, l - 1):
                if t[i] == s or t[i] == e:
                    continue
                if t[i] in middles:
                    if middles[t[i]] != t:
                        return 0
                else:
                    middles[t[i]] = t
    print starts
    print ends
    print middles
    print dif
    for t in ts:
        s = t[0]
        e = t[-1]
        if (s in middles and middles[s] != t) or (e in middles and (middles[e] != t)):
            return 0

    valids = list()
    used = set()
    used_b = set()
    for t0 in dif:
        if t0 in used:
            continue
        used.add(t0)
        v = list()
        v.append((t0, same[t0[0]], same[t0[-1]]))
        used_b.add(t0[0])
        used_b.add(t0[-1])
        t = t0
        while True:
            s = t[0]
            if s in ends:
                t = ends[s]
                if t in used:
                    return 0
                used.add(t)
                used_b.add(t[0])
                v.append((t, same[t[0]], 1))
            else:
                break
        v.reverse()
        t = t0
        while True:
            e = t[-1]
            if e in starts:
                t = starts[e]
                if t in used:
                    return 0
                used.add(t)
                used_b.add(t[-1])
                v.append((t, 1, same[t[-1]]))
            else:
                break
        print v
        valids.append(v)

    for s in same.keys():
        if s in used_b:
            continue
        valids.append([(s, same[s], 1)])

    print "valids = {0}".format(valids)

    res = 1
    for v in valids:
        for vt in v:
            (l, sc, ec) = vt
            res *= fact(sc)
            res *= fact(ec)
            res %= MOD

    res *= fact(len(valids))
    res %= MOD

#    if res != r2:
#        print "!!!! AAAAAAA"

    return res % MOD

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