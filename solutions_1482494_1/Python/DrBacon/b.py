#!/usr/bin/python

import os
import sys

fn = sys.argv[1]

fh = open(fn, "r")
T = int(fh.readline().strip())
cases = []
for i in range(T):
    N = map(int, fh.readline().strip().split(" "))[0]
    abs = []
    for j in range(N):
        ab = map(int, fh.readline().strip().split(" "))
        abs += [ab]
    cases += [(N, abs)]

fh.close()

#print cases

fh_o = open("out.txt","w")
for i in range(T):
    case = cases[i]
    (N, abs) = case
    l_ps = [0]*len(abs)
    l_all = abs
    l_2 = []
    l_left = l_all
    stars = 0
    failed = 0
    attempts = 0
    while len(filter(lambda y: l_ps[y] < 2, range(N))) > 0:
        #try to complete levels
        js = filter(lambda x: l_all[x][1] <= stars, filter(lambda y: l_ps[y] < 2, range(N)))
        if len(js) > 0:
            for j in js:
                stars += 2-l_ps[j]
                l_ps[j]=2
                attempts += 1
                #print l_ps, j
        else:
            #try to get 1 star
            js = filter(lambda x: l_all[x][0] <= stars, filter(lambda y: l_ps[y] == 0, range(N)))
            if len(js) > 0:
                max_j = max(map(lambda x: l_all[x][1], js))
                js = filter(lambda x: l_all[x][1] == max_j, js)
                j = js[0]
                stars +=1
                l_ps[j]=1
                attempts += 1
                #print l_ps, j
            else:
                failed = 1
                break
    #print failed, abs, attempts
    if failed == 1:
        print >> fh_o, "Case #"+str(i+1)+": Too Bad"
    else:
        print >> fh_o, "Case #"+str(i+1)+": "+str(attempts)

fh_o.close()
