""" imports """
import glob, pprint, pickle, os, time, sys
import copy
from numpy import array, sin, cos
import bisect

""" global variables """

""" classes """

def solvewar(naomi, ken):
    ken = copy.deepcopy(ken)
    points = 0
    for i in naomi:
        number = bisect.bisect_right(ken, i)
        if number==len(ken):
            points+=1
            ken = ken[1:]
        else:
            del ken[number]
    return points

def solvedeceit(naomi, ken):
    naomi = copy.deepcopy(naomi)
    points = 0
    for i in ken:
        number = bisect.bisect_right(naomi, i)
        if number==len(naomi):
            return points
        else:
            del naomi[number]
            points+=1
    return points

""" functions """
def solve(naomi, ken):
    naomi.sort()
    ken.sort()
    return solvedeceit(naomi, ken),solvewar(naomi, ken)

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
        numfloats = read_ints()
        naomi = read_floats()
        ken = read_floats()
        (answer1, answer2) = solve(naomi, ken)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {} {}".format(questionindex+1, answer1, answer2)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)