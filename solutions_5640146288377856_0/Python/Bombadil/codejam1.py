#! /usr/bin/python -tt
# -*- coding: utf-8 -*-

from math import *

finput = open("A-small-attempt0.in","r")
foutput = open("A-small-attempt0.out","w")




T = int(finput.readline())
for n in range(T):
    line = finput.readline().split()
    print line
    R = int(line[0])
    C = int(line[1])
    W = int(line[2])

    if R == 1:
        nb = int(ceil((1.0*C)/W) +(W-1))
    else:
        print "fail"
        nb = 0


    print("Case #"+str(n+1)+": "+str(nb)+"\n")
    foutput.write("Case #"+str(n+1)+": "+str(nb)+"\n")

finput.close()
foutput.close()

    
