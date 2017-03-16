#!/usr/bin/python2.7
import sys

def war(nbs, kbs):
    loses = 0
    for nb in nbs:
        for i in range(len(kbs)):
            if kbs[i] > nb:
                kbs = kbs[:i] + kbs[i + 1:]
                loses += 1
                break
    return len(nbs) - loses

def deceitful_war(nbs, kbs):
    while len(nbs) > 0 and nbs[-1] < kbs[-1]:
        nbs = nbs[1:]
        kbs = kbs[:-1]
    return len(nbs) - war(kbs, nbs)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for tc in range(n):
        n = int(sys.stdin.readline())
        nbs = sorted(map(float, sys.stdin.readline().split()))
        kbs = sorted(map(float, sys.stdin.readline().split()))
        dw = deceitful_war(nbs, kbs)
        w = war(nbs, kbs)
        print "Case #" + str(tc + 1) + ":", dw, w
