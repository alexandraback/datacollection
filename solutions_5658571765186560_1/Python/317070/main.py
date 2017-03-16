""" imports """
import glob, pprint, pickle, os, time, sys
import copy
from numpy import array, sin, cos
import bisect

""" global variables """

""" classes """

""" functions """
def solve(x,r,c):
    if x==1:
        return "GABRIEL"
    if x>=7:
        return "RICHARD"
    if (r*c)%x != 0:
        return "RICHARD"
    if x >= 2*min(r,c)+1:
        return "RICHARD"
    if x==2:
        return "GABRIEL"
    if x==3:
        return "GABRIEL"
    if x==4:
        if min(r,c)==1:
            return "RICHARD"
        if min(r,c)==2:
            return "RICHARD"
        if min(r,c)==3:
            return "GABRIEL"
    if x==5:
        if min(r,c)==1:
            return "RICHARD"
        if min(r,c)==2:
            return "RICHARD"
        if min(r,c)==3:
            return "RICHARD"
        if min(r,c)==4:
            return "GABRIEL"
    if x==6:
        if min(r,c)==1:
            return "RICHARD"
        if min(r,c)==2:
            return "RICHARD"
        if min(r,c)==3:
            return "RICHARD"
        if min(r,c)==4:
            return "GABRIEL"
        if min(r,c)==5:
            return "GABRIEL"
    return "GABRIEL"

""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]
    
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        ### calculate answer ###
        x,r,c = read_ints()
        answer = solve(x,r,c)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer,)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)