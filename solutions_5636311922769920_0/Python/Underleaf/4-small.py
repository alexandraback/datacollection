# -*- coding: utf-8 -*-
import fractions
import math


#file = open('Inputs/Input.in', 'r')
with open('Inputs/D-small-attempt0.in', 'r') as infile, open('Outputs/Output.out', 'w') as outfile: 
   
    T = int(infile.readline().split('\n')[0]);
    
    for i in range(0,T):
        
        line = infile.readline().split('\n')[0].split(' ');
        K = int(line[0])
        C = int(line[1])
        S = int(line[2])

        
        result = ' '.join(str(x) for x in range(1,K+1))
        
        print 'Case #'+str(i+1)+': '+str(result)
        outfile.write('Case #'+str(i+1)+': '+str(result)+'\n')
        
    
    
    
