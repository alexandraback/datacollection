import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import itertools
import math


def tolist(i):
    if i ==0:
        return []
    return [int(c) for c in str(i)]

def toint(l):
    if not l:
        return 0
    return int("".join([str(c) for c in l]))


def solve(p):
    gl = tolist(p)
    #step 1, create number with x digits:
    x = len(gl)
    if x==1:
        return p,
    if x==1:
        tot = 1
    elif x==2:
        tot = 10
    elif x>=3:
        tot = 10
        for i in xrange(2,x):
            f = i/2
            g = i-i/2
            tot += int("9"*f) + 1 + int("9"*g)
    f = x/2
    g = x-x/2

    if gl[0] == 1 and toint(gl[1:f])==0:
        route_a = tot + toint(gl[f:])
    else:
        route_a = tot + toint(gl[:f][::-1]) + 1 + toint(gl[f:]) - 1
        #print toint(gl[:f][::-1]), toint(gl[f:])
        if toint(gl[f:])==0:
            l = tolist(toint(gl[:f])-1)[::-1]
            route_a = tot + toint(l) + 1 + toint([1]+gl[f:]) - 1

    if gl[0] == 1 and toint(gl[1:g])==0:
        route_b = tot + toint(gl[g:])
    else:
        route_b = tot + toint(gl[:g][::-1]) + 1 + toint(gl[g:]) - 1
        if toint(gl[g:])==0:
            l = tolist(toint(gl[:g])-1)[::-1]
            #print l
            #print "ti:",toint(l)

            route_b = tot + toint(l) + 1 + toint([1]+gl[g:]) - 1

    route_c = tot + (p- toint([1]+[0]*(x-1)))

    print route_a - tot
    print route_b - tot
    print route_c - tot

    if route_a - tot<0:
        print "AERROR:",p

    if route_b - tot<0:
        print "BERROR:",p

    if route_b != route_a:
        print "differ:",p


    return min([route_a,route_b,route_c]),

#print solve(11000)
#cr

output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### calculate answer ###
        (p,) = read_ints()
        answer = solve(p)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()