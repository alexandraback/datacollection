#!/usr/bin/env python
import sys

T = int(sys.stdin.readline())
casenum = 1

for i in range(0, T):
    AN = []
    AN = (sys.stdin.readline().split(' '))
    
    A = int(AN[0])
    A2 = int(A)
    N = int(AN[1])
    
    listOfMotes = []
    listOfMotes = (sys.stdin.readline().split(' '))
    listOfMotes.sort(key=int)
    
    listOfMotes2 = list(listOfMotes)
    
    operations = 0
    operations2 = 0
    
    while(len(listOfMotes)>0):
            
        """print 'A='+str(A)+', aktualnyMote='+str(listOfMotes[0])"""
        
        
        if(int(listOfMotes[0])<A):
            A+=int(listOfMotes[0])
            listOfMotes.pop(0)
        
        else:
            if((A+(A-1))>int(listOfMotes[0])):
                operations += 1
                A += ((A-1)+int(listOfMotes[0]))
                listOfMotes.pop(0)
                
            else:
                operations += len(listOfMotes)
                break
            

  
    while(len(listOfMotes2)>0):
            
        """print 'A2='+str(A2)+', aktualnyMote2='+str(listOfMotes2[0])"""
                
        if(int(listOfMotes2[0])<A2):
            A2+=int(listOfMotes2[0])
            listOfMotes2.pop(0)
        
        else:
            if(A2!=1):
                operations2 += 1
                A2 += (A2-1)
                
            else:
                operations2 = 99999999999999999
                break
    
 
    if(operations2<operations):
        operations = operations2
    
    print 'Case #'+str(casenum)+': '+str(operations)
    casenum+=1

