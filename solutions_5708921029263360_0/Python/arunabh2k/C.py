#!/usr/bin/python
import copy
import sys
sys.setrecursionlimit(1000000)

f = open('sample.txt', 'r')
tc = int(f.readline())
#print tc
for index in range(tc):
    vals = f.readline().rstrip().split(" ")
    J = int(vals[0])
    P = int(vals[1])
    S = int(vals[2])
    K = int(vals[3])

    jp = {}
    ps = {}
    js = {}
    result = 0
    for j in range(J):
        for p in range(P):
            kjp = str(j+1) + "-" + str(p+1)
            if kjp not in jp:
                jp[kjp] = 0
            if jp[kjp] >= K :
                break
            for s in range(S):
                kps = str(p+1) + "-"  + str(s+1)
                kjs = str(j+1) + "-"  + str(s+1)
                if kps not in ps:
                    ps[kps] = 0
                if kjs not in js:
                    js[kjs] = 0
                if jp[kjp] >= K or js[kjs] >= K or ps[kps] >= K:
                    break

                jp[kjp] += 1
                js[kjs] += 1
                ps[kps] += 1
                result += 1
    jp = {}
    ps = {}
    js = {}
    print "CASE #" + str(index+1)  + ": " + str(result)
    for j in range(J):
        for p in range(P):
            kjp = str(j+1) + "-" + str(p+1)
            if kjp not in jp:
                jp[kjp] = 0
            if jp[kjp] >= K :
                break
            for s in range(S):
                kps = str(p+1) + "-"  + str(s+1)
                kjs = str(j+1) + "-"  + str(s+1)
                if kps not in ps:
                    ps[kps] = 0
                if kjs not in js:
                    js[kjs] = 0
                if jp[kjp] >= K or js[kjs] >= K or ps[kps] >= K:
                    break

                jp[kjp] += 1
                js[kjs] += 1
                ps[kps] += 1
                print str(j+1) + " " + str(p+1) + " " + str(s+1)
