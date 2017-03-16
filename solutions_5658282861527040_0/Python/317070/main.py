""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos

""" global variables """

""" classes """

""" functions """
def solve(A,B,K):
    cnt = 0
    for a in xrange(A):
        for b in xrange(B):
            if a&b<K:
                cnt+=1
    return cnt

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
        (a,b,k) = read_ints()
        answer = solve(a,b,k)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)