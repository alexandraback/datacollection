#! /usr/bin/python -tt
# -*- coding: utf-8 -*-

from math import *
import random
import scipy.misc

finput = open("B-small-attempt0.in","r")
foutput = open("B-small-attempt0.out","w")

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count


T = int(finput.readline())
for n in range(T):
    line = finput.readline().split()
    K = int(line[0])
    L = int(line[1])
    S = int(line[2])
    keys = [u for u in finput.readline()[:-1]]
    word = [u for u in finput.readline()[:-1]]
    moyba = 0.0
    maxba = 0
    stop = False

    probakeys = {}
    for k in set(keys):
        probakeys[k] = sum([1./K for a in keys if a == k])

    for u in word:
        if u not in keys:
            moyba = 0.0
            maxba = 0
            stop = True
    
    if not stop:
        overlaps = 0
        for i in range(1,L):
            print word[:i]
            print word[L-i:]
            if word[:i] == word[L-i:]:
                overlaps = i
        maxba = int(floor(1.*(S-L)/(L-overlaps)+1))

        probaword = 1.
        for a in word:
            probaword *= probakeys[a]
        
        proba = [0 for a in range(0,maxba+1)]
        if overlaps == 0:
            for n in range(0,maxba+1):
                proba[n] = scipy.misc.comb(maxba,n) * pow(1-probaword,S-L+1-n)*pow(probaword,n)
            print proba
        else:
            Niter = 100000
            txtw = ''.join(word)
            for itera in xrange(0,Niter,1):
                sing= ""
                for k in range(0,S):
                    sing += random.choice(keys)
                proba[occurrences(sing,txtw)] += 1.
            proba = [a/Niter for a in proba]
        moyba = sum([k*proba[k] for k in range(0,maxba+1)])
        


    
    print "maxba :" + str(maxba)
    print "moyba : " + str(moyba)


    print("Case #"+str(n+1)+": "+str(maxba-moyba)+"\n")
    foutput.write("Case #"+str(n+1)+": "+str(maxba-moyba)+"\n")

finput.close()
foutput.close()
    
