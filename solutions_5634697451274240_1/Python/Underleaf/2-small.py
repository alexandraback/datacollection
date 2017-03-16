# -*- coding: utf-8 -*-
import fractions
import math

def parseList(parsedString,string):
    if len(string) == 0:
        return parsedString
    if len(parsedString) != 0 and parsedString[-1] == string[0]  :
        return parseList(parsedString,string[1:])
    else:
        return parseList(parsedString+string[0],string[1:])

def reverseList(string):
    revString = ''
    for i in range(0,len(string)):
        if(string[i]=='+'):
            revString += '-'
        else:
            revString += '+'
    return revString

#file = open('Inputs/Input.in', 'r')
with open('Inputs/B-large.in', 'r') as infile, open('Outputs/Output.out', 'w') as outfile: 
   
    N = int(infile.readline().split('\n')[0]);
    
    for i in range(0,N):
        
        line = infile.readline().split('\n')[0];
        count = 0;
        
        if(line[-1] == '-'):
            count += 1
            lineParse = parseList('',reverseList(line))
        else:
            lineParse = parseList('',line)
        
        count += len(lineParse)-1
        result = count  
        
        print 'Case #'+str(i+1)+': '+str(result)
        outfile.write('Case #'+str(i+1)+': '+str(result)+'\n')
        
    
    
    
