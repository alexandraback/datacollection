# -*- coding: utf-8 -*-
import fractions
import math

#file = open('Inputs/Input.in', 'r')
with open('Inputs/A-large.in', 'r') as infile, open('Outputs/Output.out', 'w') as outfile: 
   
    T = int(infile.readline().split('\n')[0]);
    
    for i in range(0,T):
        
        list = [];
        Nstr = infile.readline().split('\n')[0]
        N0 = int(Nstr)
        N = N0
        
        if N == 0:
            result = 'INSOMNIA';
        else:
            for k in range(1,1000000):
                for Nchar in Nstr:
                    if Nchar not in list:
                        list.append(Nchar)
                    if len(list) == 10:
                        break;
                if len(list) == 10:
                    break;
                N = k*N0
                Nstr = str(N)
    
            result = Nstr
        print 'Case #'+str(i+1)+': '+str(result)
        outfile.write('Case #'+str(i+1)+': '+str(result)+'\n')      
        
        


        
    
    
    
