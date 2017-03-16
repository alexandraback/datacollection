from helpers import *
import os.path
from fractions import Fraction
import re
import sys
import math
sys.setrecursionlimit(10000)
from Queue import Queue
from collections import Counter

prefix = 'D'



def solve(global_details, prob):
    _ = global_details
    K,N,startkeys,openers,chestcontents = prob

    # simple checks for impossible inputs
    tot = Counter(startkeys + [k for r in chestcontents for k in r])
    for c in xrange(N):
        ches = Counter(chestcontents[c])
        k = openers[c]
        if tot[k] - ches[k] < 1: return 'IMPOSSIBLE'
    needed = Counter(openers)
    for k in needed.keys():
        if tot[k] < needed[k]: return 'IMPOSSIBLE'

##    print startkeys
##    for c in xrange(N):
##        print openers[c], chestcontents[c]
    

    inventory = Counter(startkeys)

    def openable():
        for i in xrange(N):
            key = openers[i]
            if key > 0 and inventory[key] > 0:
                yield key, i


    def path(numopened):
        if numopened == N: return [-1] # since [] is Falseish
        for key, chest in openable():            
            # open chest
            inventory[key] -= 1
            openers[chest] = -1
            contents = chestcontents[chest]
            for k in contents: inventory[k] += 1
                            
            cont = path(numopened+1)
            if cont: # success
                return [chest] + cont
            if key in contents: return False
            
            # return to old state
            inventory[key] += 1
            openers[chest] = key
            for k in contents: inventory[k] -= 1            
        return False
        
    
    
    ret = path(0)

    if ret == False: return 'IMPOSSIBLE'
    return ' '.join([str(c+1) for c in ret[0:N]])
    




def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    K, N = intline(f)
    startkeys = intline(f)
    lines = [intline(f) for i in xrange(N)]
    openers = [line[0] for line in lines]
    keys = [line[2:] for line in lines]
    return K,N,startkeys,openers,keys

    
        


def read_global_details(f):
    numcases = firstint(f)
    return None, numcases


def solve_many(filename):
    print 'Solving file', filename
    f = open(filename + inextension, 'r')
    of = open(filename + outextension, 'w')
    global_details, numcases  = read_global_details(f)
    for cnum in xrange(1, numcases+1):
        p = read_single_problem(f)
        line = 'Case #{}: {}'.format(cnum, solve(global_details, p))
        print line
        of.write(line + '\n')
        
    f.close()
    of.close()
    return True



inextension, outextension = '.in', '.out'
largesuffix = '-large'
smallsuffix = '-small-attempt4'
tinysuffix = '-tiny'

def fexists(fname):
    return os.path.isfile(fname + inextension)

if __name__ == '__main__':
    tinyinstancefile = prefix + tinysuffix
    smallinstancefile = prefix + smallsuffix
    largeinstancefile = prefix + largesuffix
    if fexists(largeinstancefile): solve_many(largeinstancefile)
    elif fexists(smallinstancefile): solve_many(smallinstancefile)
    elif fexists(tinyinstancefile): solve_many(tinyinstancefile)
    else: print 'NO INPUT FILES DETECTED'
