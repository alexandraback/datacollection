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

lineNum = 1
for casenum in range(numCases):
    print (casenum+1)
    N = int(lines[lineNum])
    trips = []
    Bs = []
    As = []
    for i in range(N):
        ai = int(lines[lineNum+i+1].split(' ')[0])
        bi = int(lines[lineNum+i+1].split(' ')[1])
        t = [ai, bi, 0]
        trips.append(t)
        Bs.append(bi)
        As.append(ai)
    curScore = 0
    count = 0
    while len(Bs)>0:
        B = min(Bs)
        error = False 
        if curScore >= B:
            for t in trips:
                if t[1]==B:
                    if t[2]==1:
                        curScore += 1
                        Bs.remove(B)
                        t[2]=2
                        count += 1
                        break
                    elif t[2]==0:
                        As.remove(t[0])
                        curScore += 2
                        Bs.remove(B)
                        t[2]=2
                        count += 1
                        break
        else:
            while B > curScore:
                if len(As)==0:
                    error = True
                    break
                A = min(As)
                if A > curScore:
                    error = True #can't win!
                    break
                else:
                    for t in trips: #find it and update score
                        if t[0]==A and t[2]==0:
                            As.remove(A)
                            curScore += 1
                            t[2]=1
                            count += 1
                            break
            if error:
                break
        if casenum==87:
            print trips, curScore, count
    if error:
        output += "Case #"+str(casenum+1)+": Too Bad\n"
    else:
        output += "Case #"+str(casenum+1)+": "+str(count)+"\n"
    lineNum += N + 1


output=output[:-1]
fw = open(namefile+'.txt', 'w')
fw.write(output)
fw.close()
