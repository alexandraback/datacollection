'''
Created on Apr 27, 2012

@author: Phil
'''

import os
thisname = os.path.basename(__file__)
namefile = thisname.split('.')[0] #filename (without the extension)

fr = open(namefile+'.in', 'r')
fc = fr.read()
fr.close()

lines = fc.split('\n')
output = ""
numCases = int(lines[0])
linenum = 1

for casenum in range(numCases):
    N = int(lines[linenum])
    IF = []
    for i in range(N):
        s = lines[linenum+i+1].split(' ')[1:]
        parents = []
        for st in s:
            parents.append(int(st))
        IF.append(parents)
    linenum = linenum+N+1
    falses = [False for i in range(N)]
    F = [falses[:] for i in range(N)]
    br = False
    for xyz in range(N):
        for m in range(len(IF)):
            for n in IF[m]:
                F[m][n-1] = True
                F[m] = [F[m][i] or F[n-1][i] for i in range(len(F[m]))]
            for n in range(len(IF[m])):
                for n2 in range(n+1,len(IF[m])):
                    if any(F[IF[m][n]-1][i] and F[IF[m][n2]-1][i] for i in range(len(F[IF[m][n]-1]))):
                        br = True
                        break
                    if F[IF[m][n2]-1][IF[m][n]-1] or F[IF[m][n]-1][IF[m][n2]-1]:
                        br = True
                        break
                if br:
                    break
        if br:
            break
    if br:
        output += "Case #"+str(casenum+1)+": Yes\n"
    else:
        output += "Case #"+str(casenum+1)+": No\n"    
            
output=output[:-1]
fw = open(namefile+'.txt', 'w')
fw.write(output)
fw.close()
