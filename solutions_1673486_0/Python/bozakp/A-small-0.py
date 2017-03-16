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

for casenum in range(numCases):
    A = int(lines[casenum*2+1].split(' ')[0])      #casenum is 0...(numcases-1)
    B = int(lines[casenum*2+1].split(' ')[1])
    ps = []
    for x in lines[casenum*2+2].split(' '):
        ps.append(float(x))
    #case1
    prodps = 1.0
    for p in ps:
        prodps = prodps*p
    eCase1 = prodps*(B-A)+(1.0-prodps)*(2*B - A + 1)
    #case2
    oldmin = 50000
    for n in range(A): #press backspace A-n times
        prodps = 1.0
        for i in range(n):
            prodps = prodps*ps[i]
        newmin = prodps*(B + A - 2*n) + (1.0 - prodps)*(2*B + A - 2*n + 1)
        oldmin = newmin if (newmin < oldmin) else oldmin
    eCase2 = oldmin
    #case3
    eCase3 = B+1
    best = min([eCase1, eCase2, eCase3])
    output += "Case #"+str(casenum+1)+": "+str(best+1.0)+"\n"

output=output[:-1]
fw = open(namefile+'.txt', 'w')
fw.write(output)
fw.close()
