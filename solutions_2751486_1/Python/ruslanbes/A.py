import math
#import numpy
#import sys
import re
#sys.setrecursionlimit(10000)

def Output(CaseN, res):
    outputLine = "Case #"+str(CaseN)+": "+str(res)
    fw.write(outputLine + "\n")


##################################
name = 'A-practice'
name = 'A-small'
name = 'A-large'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()
T = int( lines.pop(0) )

#vowels = ['a','e','i','o','u']
cons = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']
#consRe = '[bcdfghjklmnpqrstvwxyz]' 
#matches = re.finditer(r'([bcdfghjklmnpqrstvwxyz]{'+n+'})',s)
#results = [int(match.group(1)) for match in matches]    

def getPosOfNCons(name,n):
    l = len(name)
    pos = []
    consFound = 0
    for i in xrange(l):
        if name[i] in cons:
            consFound +=1
            if consFound >= n:
                pos.append(i-n+1)
        else:
            consFound = 0
    return pos
    
def getTotalCount(pos, n, l):
    total = 0
    prev_p = -1
    for p in pos:
        #print p, prev_p
        before = p
        after = l-p-n
        #for i in xrange(before+1):
        #    for j in xrange(after+1):

        total += (before+1-prev_p-1)*(after+1)
        prev_p = p
    return total

for i in xrange(T):
    #print i
    name, n = lines.pop(0).split(' ')
    n = int(n)
    #print name, n, '------------'
    pos = getPosOfNCons(name, n)
    res = getTotalCount(pos, n, len(name))
    Output(i+1, res)