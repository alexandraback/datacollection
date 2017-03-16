# -*- coding: utf-8 -*-

from pylab import *
import numpy

infile = open('input.txt', 'r')
outfile = open("cookieclicker-output.txt", "w")

numcases = int(infile.readline())

for case in range(0, numcases):
    els = infile.readline().split(" ")
    C = float(els[0]) 
    F = float(els[1])
    X = float(els[2])
    
    totalTime = 0
    beforeNext = 0
    numFarms = 0
    speed = 2

    if C > X:
        totalTime = X / speed
    else:
        totalTime = C / speed
        
        while (True):
            dt = (C / F)
            #print(dt)
            if (X <= C + dt * speed):
                #over
                totalTime = totalTime + (X - C) / speed
                break
            else:
                #still not there
                speed = speed + F
                addT = C / speed
                totalTime = totalTime + addT
            
    print('Case #',(case+1),': ',totalTime);
    outfile.write('Case #'+str(case+1)+': '+str(totalTime)+'\n')

outfile.close()
    

