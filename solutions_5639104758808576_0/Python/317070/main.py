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
    max_shy = q
    list_of_ints = [int(i) for i in str(r)]
    total = 0
    maxdiff = 0
    for shyness, numpeople in enumerate(list_of_ints):
        if total<shyness:
            diff = shyness-total
            if diff>maxdiff:
                maxdiff = diff
        total += numpeople
    return maxdiff
    
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
        (q,r) = f.readline().strip().split(' ')
        answer = solve(int(q),r)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, "%s"%answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)