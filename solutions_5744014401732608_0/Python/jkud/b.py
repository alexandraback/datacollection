#!/usr/bin/env python

def solve(c, B, M):
    if B == 2:
        if M == 1:
            print "Case #%d: POSSIBLE" % c
            print "01"
            print "00"
            return
        else:
            print "Case #%d: IMPOSSIBLE" % c
            return
    if M > 2**(B-2):
        print "Case #%d: IMPOSSIBLE" % c
        return
    print "Case #%d: POSSIBLE" % c
    row = "0"
    pw = 2**(B-3)
    while pw > 0:
        if M >= pw:
            row += "1"
            M = M - pw
        else:
            row += "0"
        pw /= 2
    row += "1" if M else "0"
    print row
    for i in range(1, B):
        row = ""
        for j in range(B):
            row += "1" if j > i else "0"
        print row


T = int(raw_input().strip())
for t in range(T):
    B, M = [int(i) for i in raw_input().strip().split()]
    solve(t+1, B, M)
