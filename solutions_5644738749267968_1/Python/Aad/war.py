
from itertools import *
import sys

debug = False

def log(*argv):
    if debug:
        print " ".join(imap(str, argv))

def deceitful_war_play(N, Wn, Wk):
    n = 0
    for _ in xrange(N):
        log("loop :")
        log("Wn :", Wn)
        log("Wk :", Wk)
        if Wn[0] > Wk[0]:
            del Wn[0]
            del Wk[0]
            n += 1
        else:
            del Wn[0]
            del Wk[-1]
    return n

def war_play(Wn, Wk):
    n = 0
    for Cn in Wn:
        if Cn > Wk[-1]:
            del Wk[0]
            n += 1
        else:
            for Ck in Wk:
                if Ck > Cn:
                    break
            Wk.remove(Ck)
    return n

def main(f, case):
    N = int(f.readline())
    Wn = sorted(map(float, f.readline().split()))
    Wk = sorted(map(float, f.readline().split()))
    n = war_play(Wn[:], Wk[:])
    m = deceitful_war_play(N, Wn, Wk)
    print "Case #" + str(case) + ":", m, n

with open(sys.argv[1]) as f:
    N = int(f.readline())
    for i in xrange(N):
        main(f, i+1)
