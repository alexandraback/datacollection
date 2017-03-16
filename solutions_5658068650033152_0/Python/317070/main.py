""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos

""" global variables """

""" classes """

""" functions """

def solve(n,m,k):
    if n<=2 or m<=2:
        return k
    if k<5:
        return k
    i,j = 3,3
    while i*j-3<k:
        if i<j and i<n:
            i+=1
        elif i==j and j<m:
            j+=1
        elif i==n and j<m:
            j+=1
        elif j==m and i<n:
            i+=1
        else:
            break
    if i*j-4<k:
        return (i-2)*2+(j-2)*2 + (k-(i*j-4))
    else:
        return (i-2)*2+(j-2)*2

""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        (n,m,k) = read_ints()
        ### calculate answer ###
        answer = solve(n,m,k)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)