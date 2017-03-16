import sys, os

def kmpshift(pattern):
    shifts = [None] * (len(pattern) + 1)
    shift = 1
    for pos in range(len(pattern) + 1):
        while shift < pos and pattern[pos-1] != pattern[pos-shift-1]:
            shift += shifts[pos-shift-1]
        shifts[pos] = shift
    return shifts

tn = int(sys.stdin.readline())
for ti in xrange(1, tn+1):
    k, l, s = map(int, sys.stdin.readline().split())
    keys = sys.stdin.readline().strip()
    word = sys.stdin.readline().strip()
    shifts = kmpshift(word)
    word += '\0'
    #print shifts

    maxdp = [[None for j in xrange(l)] for i in xrange(s+1)]
    for i in xrange(l):
        maxdp[0][i] = 0
    for i in xrange(1, s+1):
        for j in xrange(l):
            for x in keys:
                mlen = j
                while mlen >= 0 and word[mlen] != x:
                    mlen -= shifts[mlen]
                mlen += 1
                r = None
                if mlen == l:
                    mlen -= shifts[mlen]
                    r = 1 + maxdp[i-1][mlen]
                else:
                    r = maxdp[i-1][mlen]
                if maxdp[i][j] is None or maxdp[i][j] < r:
                    maxdp[i][j] = r

    avgdp = [[None for j in xrange(l)] for i in xrange(s+1)]
    for i in xrange(l):
        avgdp[0][i] = 0.0
    for i in xrange(1, s+1):
        for j in xrange(l):
            avgdp[i][j] = 0.0
            for x in keys:
                mlen = j
                while mlen >= 0 and word[mlen] != x:
                    mlen -= shifts[mlen]
                mlen += 1
                r = None
                if mlen == l:
                    mlen -= shifts[mlen]
                    r = 1 + avgdp[i-1][mlen]
                else:
                    r = avgdp[i-1][mlen]
                avgdp[i][j] += r/k
    #print maxdp
    ret = maxdp[s][0] - avgdp[s][0]
    if ret < 1e-8:
        ret = 0.0
    print 'Case #{0}: {1:.8}'.format(ti, ret)
    sys.stdout.flush()
