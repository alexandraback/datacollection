# -*- coding: utf-8 -*-

from itertools import repeat
from pylab import *
import numpy

infile = open('input.txt', 'r')
outfile = open("minesweeper-big-output.txt", "w")

def printM(m):
    print(shape(m))
    for i in range(0,shape(m)[0]):
        for j in range(0, shape(m)[1]):
            print m[i,j],
            outfile.write(m[i,j])
        
        print 
        outfile.write('\n')  

numcases = int(infile.readline())

wrong = 0

for case in range(0, numcases):
    els = infile.readline().split(" ")
    R = int(els[0]) 
    C = int(els[1])
    M = int(els[2])
    
    W = R
    H = C
    
    if (W > H):
        W = C
        H = R
    
    Free = R*C - M
    
    Possible = True
    Answer = empty((1,1), dtype=str);
    Answer.fill('.')
    
    if Free == 1:
        Possible = True
        Answer = empty((W,H), dtype=str)
        Answer.fill('*')
        
        Answer[0,0] = 'c';
        
    else:
        if W == 1:
            if Free < 2:
                Possible = False
            else:
                Possible = True
                
                Answer = matrix((['c']) + list(repeat('.',Free-1)) + list(repeat('*',M)))
            
        else:
            if W == 2:
                if (Free < 4) or (Free % 2 == 1):
                    Possible = False
                else:
                    Answer = matrix(vstack([(['c']) + list(repeat('.',Free/2-1)) + list(repeat('*',M/2)), 
                                            list(repeat('.',Free/2)) + list(repeat('*',M/2))]))
                
            else:
                if (Free == 7) or (Free == 5) or (Free < 4):
                    Possible = False
    
                else:
                    D = W
    
                    while (Free % D == 1) or (Free / D < 2):
                        D = D - 1
                    
                    if (Free / D > H):
                        D = 1
                    
                    if D == 1:
                        X = W
                        W = H
                        H = X
                        D = W
                        
                    while (Free % D == 1) or (Free / D < 2):
                        D = D - 1
    
                    if (Free / D > H):
                        D = 1                    
                        
                    if D == 1:
                        Possible = True
                        #print('XXX Impossible', R, C, M, Free)
                        #wrong = wrong + 1
                                         
                        Answer = empty((W,H), dtype=str)   
                        Answer.fill('*')
                        
                        Answer[0:W,0:(int(Free / W) - 1)] = '.'
                        Answer[0:W-1,int(Free / W)-1] = '.'
                        Answer[0:2,int(Free / W)] = '.'
                        
                        Answer[0,0] = 'c'
                    else:
                        Possible = True
                        Answer = empty((W,H), dtype=str)
                        Answer.fill('*')
                        
                        Answer[0:D,0:int(Free / D)] = '.'
                        
                        if Free % D != 0:
                            if int(Free/D) > H -1:
                                Answer[D,0:(Free % D)] = '.'
                            else:
                                Answer[0:(Free % D),int(Free/D)] = '.'
                        
                        Answer[0,0] = 'c'                       
                             
                
    #outfile.write(str(R)+' '+str(C)+' '+str(M)+ '\n')
    if Possible:
        print("Case #"+str(case + 1)+":")
        outfile.write("Case #"+str(case + 1)+":\n")

        if W == R:
            printM(Answer)
        else:
            printM(transpose(Answer))
            
    else:
        print("Case #"+str(case + 1)+": Impossible")
        outfile.write("Case #"+str(case + 1)+":\nImpossible\n")
        
    #if case == 7:
    #    break;        
    
outfile.close()

print(wrong)