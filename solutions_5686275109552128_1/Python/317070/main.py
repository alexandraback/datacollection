""" imports """
import glob, pprint, pickle, os, time, sys
from copy import deepcopy
from numpy import array, sin, cos
from math import log, ceil
import itertools
from operator import itemgetter
""" global variables """

def solve(plates, extra=0, end=-1):
    best = max(plates)+extra
    
    #print plates
    if end==-1:
        end=best-1
    
    if end==extra:
        return best
    
    #so maximally best-1 special minutes
    index, element = max(enumerate(plates), key=itemgetter(1))
    
    for i in xrange(1,element/2+1):
        nplates = plates[:]
        nplates[index] = i
        nplates.append(element - i)
        newbest = solve(nplates,extra=extra+1,end=end)
        if newbest<best:
            best = newbest
    return best

def solve2(plates):
    best = max(plates)
    for i in xrange(1,best-1):
        #how many steps would it take, to get all plates to i or less?
        steps = 0
        for plate in plates:
            if plate>i:
                steps += plate/i-1
                if plate%i != 0:
                    steps += 1
        if i+steps<best:
            best = i+steps
    return best
        
        
    
""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]    
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]
    
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        ### calculate answer ###
        diners = read_ints()
        plates = read_ints()
        answer = solve2(plates)
        #answer2 = solve2(plates)
        #assert answer==answer2, "Problem"
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)