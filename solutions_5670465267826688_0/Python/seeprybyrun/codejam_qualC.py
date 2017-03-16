#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
import time
import copy

qm = {    '1*1': '1',
          '1*i': 'i',
          '1*j': 'j',
          '1*k': 'k',
          'i*1': 'i',
          'i*i': '-1',
          'i*j': 'k',
          'i*k': '-j',
          'j*1': 'j', # yeah, i screwed this line up earlier...
          'j*i': '-k',
          'j*j': '-1',
          'j*k': 'i',
          'k*1': 'k',
          'k*i': 'j',
          'k*j': '-i',
          'k*k': '-1' }

def qMult(a,b):
    isNegative = False
    if a[0] == '-':
        a = a[1:]
        isNegative = not isNegative
    if b[0] == '-':
        b = b[1:]
        isNegative = not isNegative
    prod = qm[a+'*'+b]

    # remove any negative sign if the product is already negated
    if prod[0] == '-' and isNegative:
        prod = prod[1:]
    # add a negative sign if not there and the product is negated
    elif prod[0] != '-' and isNegative:
        prod = '-' + prod

    return prod

##assert qMult('i','j') == 'k'
##assert qMult('i','i') == '-1'
##assert qMult('-j','-j') == '-1'
##assert qMult('-j','j') == '1'
##assert qMult('j','-j') == '1'
##assert qMult('k','-1') == '-k'
##print 'qMult test cases passed!'

def qReduce(s):
    '''assumes s is a string of characters i,j,k'''
    prod = '1'
    for c in s:
        prod = qMult(prod,c)
    return prod

##assert qReduce('iii') == '-i'
##assert qReduce('ijk') == '-1'
##assert qReduce('i') == 'i'
##assert qReduce('') == '1'
##print 'qReduce test cases passed!'

##s = 'kiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiijikiiji'
##print qReduce(s)
##print qReduce('kiijikiij')
##print qReduce('i'+s+'kiijikiij')

def solve(s,X):
    if len(s)*X < 3: return 'NO' # too short
    
    p = qReduce(s)
    fullProd = '1'
    for _ in range(X):
        fullProd = qMult(fullProd,p)
##    print fullProd
##    assert fullProd == qReduce(s*X)

    # by associativity, if we can reduce to 'ijk', then we can
    # further reduce to 'kk' == '-1'
    if fullProd != '-1': return 'NO'
    
    # in this case, it's enough to check that we have an initial
    # substring that reduces to 'i' and a final substring that
    # reduces to 'k': forces the middle substring to be 'j'
    s = s*X
    prod = '1'
    for iEndpt,c in enumerate(s[:-2]):
        prod = qMult(prod,c)
        if prod == 'i': break
    if prod != 'i': return 'NO' # this means that no initial substring
                                # can be made to equal i
    prod = '1'
    for c in s[iEndpt+2:][::-1]:
        prod = qMult(c,prod)
        if prod == 'k': break
    if prod != 'k': return 'NO' # this means there's no final substring
                                # not overlapping the smallest initial
                                # i-substring and leaving at least one
                                # character for the j-substring

    return 'YES' # we've successfully split the string into i+j+k
    
##    s = s*X
##    prod1 = '1'
##    for ep1 in range(1,len(s)-1):
##        prod1 = qMult(prod1,s[ep1-1])
##        if prod1 != 'i': continue
##        prod3 = '1'
##        prod3str = ''
##        for ep2 in range(len(s)-1,ep1+1,-1):
##            d = s[ep2]
##            prod3str = d + prod3str
####            print d,prod3,qMult(d,prod3)
##            prod3 = qMult(d,prod3)
##            if prod3 != 'k': continue
####            print prod3str,prod3
##            assert prod3str == s[ep2:]
##            assert qReduce(prod3str) == qReduce(s[ep2:])
####            print s[:ep1],'||',s[ep1:ep2],'||',s[ep2:]
##            assert qReduce(s[:ep1]) == 'i'
##            assert qReduce(s[ep1:ep2]) == 'j'
##            assert qReduce(s[ep2:]) == 'k'
##            return 'YES'
##    return 'NO'

T = 0 # number of test cases - can ignore this
L = 0 # number of letters in the test case - can ignore this
X = 0 # number of repetitions in the test case
whichCase = 1

# read input
infile = sys.argv[1] #input("Enter the file name: ")
f = open(infile,'r')

t0 = time.clock()

for i,line in enumerate(f.readlines()):
#    print i,line
    line = line.strip()
    if not line:
        break
    
    # first line tells us T
    if i == 0:
        T = int(line)
    elif i%2 == 1:
        L,X = map(int,line.split())
#        print '{},{},{}'.format(X,R,C),
    elif i%2 == 0:
        s = line
        print 'Case #{}: {}'.format(whichCase,solve(s,X))
        whichCase += 1

t1 = time.clock()
f.close()
#print "seconds elapsed: {0}".format(t1-t0)
