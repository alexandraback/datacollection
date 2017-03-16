# -*- coding: utf-8 -*-
import fractions
import math

def parseNum(numList,base):
    result = 0
    l = len(numList)
    for i in range(0,l):
       result += (int(numList[i])-1) * (base ** (l-i-1))
    return result+1

with open('Inputs/D-large.in', 'r') as infile, open('Outputs/Output.out', 'w') as outfile: 
   
    T = int(infile.readline().split('\n')[0]);
    
    for i in range(0,T):
        
        line = infile.readline().split('\n')[0].split(' ');
        K = int(line[0])
        C = int(line[1])
        S = int(line[2])
         
        result = '' 
        if K > C*S :
            result = ' IMPOSSIBLE'
        else :
            for j in range(0,int(math.ceil(float(K)/C))):
                if((j+1)*C <= K):
                    num = range(j*C+1,(j+1)*C+1)
                    result += ' ' + str(parseNum(num,K))
                else :
                    num = range(j*C+1,K+1)+[1]*(C-(K-j*C))
                    result += ' ' + str(parseNum(num,K))

        print 'Case #'+str(i+1)+':'+str(result)
        outfile.write('Case #'+str(i+1)+':'+str(result)+'\n')
        
    
    
    
