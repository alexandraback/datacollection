""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos

""" global variables """

""" classes """

""" functions """
def solve(c,f,x):
    production = 2
    totaltime = 0.0
    while True:
        paybacktime_farm = c/production + c/f
        finished = x/production
        if finished<paybacktime_farm:
            # don't buy another farm
            return totaltime + finished
        else:
            # buy another farm
            totaltime += c/production
            production += f

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
        (c,ef,x) = read_floats()
        answer = solve(c,ef,x)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {:.7f}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)