""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import itertools
import math
""" global variables """

""" classes """
        

""" functions """
def solve(q,r):
    n=2
    l = []
    while n<=2**40:
        if n*q>=r:
            q = n*q-r
            r = n*r
            l.append(1)
        else:
            l.append(0)
        n*=2
    if q!=0:
        return "impossible"
    for p,i in enumerate(l):
        if i==1:
            return p+1
    return l
    
def fractolist(q,r):
    pass
""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        ### calculate answer ###
        (q,r) = read_frac()
        answer = solve(q,r)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, "%s"%answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)