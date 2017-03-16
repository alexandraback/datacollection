#!/usr/bin/python

possibilities = [(2, 2, 2), (2, 2, 3), (2, 2, 4), (2, 2, 5), (2, 3, 3), (2, 3, 4), (2, 3, 5), (2, 4, 4), (2, 4, 5), (2, 5, 5), (3, 3, 3), (3, 3, 4), (3, 3, 5), (3, 4, 4), (3, 4, 5), (3, 5, 5), (4, 4, 4), (4, 4, 5), (4, 5, 5), (5, 5, 5)]

freq = {}
for (a,b,c) in possibilities:
    for i in xrange(1,126):
        freq[(a,b,c,i)] = 0
    l = [1,a,b,c,a*b,a*c,b*c,a*b*c]
    for i in l:
        freq[(a,b,c,i)] += 1

R = 100
N = 3
M = 5
K = 7

eskjl = raw_input()
eskjl = raw_input()

print "Case #1:"
for i in xrange(1,R+1):
    product = map(int, raw_input().split())
    best = (1,1,1)
    maxprob = -1
    for (a,b,c) in possibilities:
        #print (a,b,c)
        prob = 1
        for p in product:
            prob *= freq[(a,b,c,p)]
            #print "%d : %d" % (p,prob)
        if (prob > maxprob):
            best = (a,b,c)
            maxprob = prob
    print "%s%s%s" % best
