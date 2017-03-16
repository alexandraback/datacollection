# GCJ 2014 Round 1C, Problem C, Jeremy Holman

import sys
import math

DEBUG = False

T = int(sys.stdin.readline().strip())

for i in xrange(T):
    N, M, K = map(int, sys.stdin.readline().strip().split(" "))

    answer = 1001

    if DEBUG: print
    if DEBUG: print "working on", K

    if K < 5 or N == 1 or N == 2 or M == 1 or M == 2:
        answer = K
    else:
        for n in xrange(3, N+1):
            m_dense = int(math.ceil(float(K)/n))
            if m_dense <= M:
                if DEBUG: print "  dense", n, m_dense
                if m_dense < 3:
                    proposal = K
                else:
                    proposal = 2 * (n+m_dense) - 4
                if proposal < answer:
                    if DEBUG: print "    CANDIDATE", proposal
                    answer = proposal

            for extra in range(5):
                m = int(math.ceil(float(K+extra)/n))
                if m <= M and m >= 3:
                    proposal = 2 * (n+m) - 4 - extra
                    if DEBUG: print "  sparse", n, m, extra
                    if proposal < answer:
                        if DEBUG: print "    CANDIDATE", proposal
                        answer = proposal

    if answer == 1001:
        answer = "TOTALLY CRAZY WTF   " + str(answer)

    print "Case #%d:" % (i+1),
    print answer



