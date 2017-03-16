inputFile = open('A-small-attempt0 (1).in', 'r')
file1 = inputFile

from fractions import gcd

file2 = open("Part_Elf_Solution.txt", 'w')
### Actual Function ###

def magicFunction (file1):
#### ---------------READ FILE------------------ ####    
    line1 = (file1.readline())
    [P, Q] = [float(s) for s in line1.split('/')]

    G = gcd(P,Q)
    P /= G
    Q /= G


#### ---------------ACTUAL FUNCTION------------- #####
    ancestors = 0
    if 2**40 % Q != 0:
        return "impossible"
    else:
        X = float(P/Q)
        while X < 1:
            ancestors += 1
            if Q % 2 == 0: 
                Q /= 2.0
                X *= 2.0
                
    if ancestors <= 40:      
        return ancestors
    else:
        return "impossible"
'''
#### ------------------------------------------------------------------ #####
#-END FUNCTION-# 
#### ------------------------------------------------------------------ #####
'''   
#### -------------------PRINTING PART DON'T TOUCH-------------------- #####

caseNumber = int(file1.readline())

for caseN in range(caseNumber):
    N = caseN + 1
    print N
    #print("Case #"+str(N)+ '' +  ":" + ' ' + str(magicFunction(file1)) + '\n')
    file2.write("Case #"+str(N)+ '' +  ":" + ' ' + str(magicFunction(file1)) + '\n')
file2.close()
