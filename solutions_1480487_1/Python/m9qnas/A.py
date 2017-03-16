#!/usr/bin/python

import sys
from multiprocessing import Pool
import operator


IN = iter(sys.stdin.read().split())

def get_cases():
    T = int(next(IN))
    for case in xrange(1,T+1):
        N = int(next(IN))
        S = [0]*N
        for i in xrange(N):
            S[i] = int(next(IN))
        yield case, N, S


def get_result(args):
    case, N, S = args

    X = sum(S)
    Ss = sorted(zip(S, xrange(N)))
    Ssum = sorted(zip(S, xrange(N)))

    XX = [0] * N

    for i in xrange(1, N):
        Ssum[i] = (Ssum[i-1][0]+Ssum[i][0], Ssum[i][1])
        XX[i] = (i+1) * Ss[i][0] - Ssum[i][0]

    MS = {}

    j = len(filter(lambda x: x <= X, XX))

    ss = Ssum[j-1][0]

    for ssi in xrange(j):
        s, i = Ss[ssi]
        MS[i] = 100 * ((float(X + ss)/j) - float(s)) / float(X)

    for ssi in xrange(j, N):
        s, i = Ss[ssi]
        MS[i] = float(0)

    result =  ' '.join(map(str, map(operator.itemgetter(1), sorted(MS.iteritems())) ))

    return case, result


if __name__ == "__main__":
    for case, result in Pool(4).map(get_result, get_cases()):
        print "Case #%d:" % case, result
