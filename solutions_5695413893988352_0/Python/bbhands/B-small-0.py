#!/usr/bin/python
# -*- coding: utf-8 -*-

T = int(raw_input().strip())

for t in xrange(0, T):
    C, J = tuple(raw_input().strip().split())
    C = list(C)
    J = list(J)
    CC = []
    JJ = []
    for (c, j) in zip(C, J):
        if c == '?' and j == '?':
            CC.append('0')
            JJ.append('0')
        elif c == j:
            CC.append(c)
            JJ.append(j)
        elif c == '?':
            CC.append(j)
            JJ.append(j)
        elif j == '?':
            CC.append(c)
            JJ.append(c)
        else:
            if int(c) > int(j):
                mode = 'c'
            else:
                mode = 'j'
            break
    ii = len(CC)
    if mode == 'c':
        for i in range(ii, len(C)):
            if C[i] == '?':
                CC.append('0')
            else:
                CC.append(C[i])
            
            if J[i] == '?':
                JJ.append('9')
            else:
                JJ.append(J[i])
    else:
        for i in range(ii, len(C)):
            if C[i] == '?':
                CC.append('9')
            else:
                CC.append(C[i])
            
            if J[i] == '?':
                JJ.append('0')
            else:
                JJ.append(J[i])

    answer = " ".join(["".join(CC), "".join(JJ)])

    print "Case #%i: %s\n" % (t+1, answer)


