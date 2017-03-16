'''
Created on Apr 27, 2012

@author: Phil
'''
import math

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
    print casenum
    l = lines[linenum].split(' ')
    D = float(l[0])
    N = int(l[1])
    A = int(l[2])
    tx = []
    for i in range(N):
        l = lines[linenum+1+i].split(' ')
        tx.append([float(l[0]), float(l[1])])
    linenum += N + 1
    As = []
    sts = lines[linenum].split(' ')
    for i in range(A):
        As.append(float(sts[i]))
    linenum += 1
    output += "Case #"+str(casenum+1)+":\n"
    for a in As:
        v = 0.0
        ti = 0
        x = 0.0
        if len(tx)>1:
            while tx[ti+1][1] < D:
                if v > float(tx[ti+1][1]-tx[ti][1])/(tx[ti+1][0]-tx[ti][0]):
                    x = tx[ti+1][1]
                    v = float(tx[ti+1][1]-tx[ti][1])/(tx[ti+1][0]-tx[ti][0])
                    ti += 1
                else:
                    deltat = tx[ti+1][0]-tx[ti][0]
                    if (x+v*deltat+a*deltat*deltat/2.0)>tx[ti+1][1]:
                        x = tx[ti+1][1]
                        v = float(tx[ti+1][1]-tx[ti][1])/(tx[ti+1][0]-tx[ti][0])
                        ti += 1
                    else:
                        x = x+v*deltat+a*deltat*deltat
                        v = v+a*deltat
                        ti += 1
            tca = (-1*v+math.sqrt(v*v+2*a*(D-x)))/a
            cv = float(tx[ti+1][1]-tx[ti][1])/(tx[ti+1][0]-tx[ti][0])
            ft = max([tca, (D-tx[ti][1])/cv])
            output += str(ft + tx[ti][0])+"\n" 
        else:
            ft = (-1*v+math.sqrt(v*v+2*a*(D-x)))/a
            output += str(ft + tx[ti][0])+"\n"
                     
   
output=output[:-1]
fw = open(namefile+'.txt', 'w')
fw.write(output)
fw.close()
