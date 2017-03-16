
# -*- coding: cp932 -*-

import sys


#inputfile = "sample.in"
#inputfile = "A-small-attempt1.in"
inputfile = "A-large.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')

tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    line = f.readline().rstrip()
    la = line.split()
    
    A = int(la[0])
    N = int(la[1])

    line = f.readline().rstrip()
    la = line.split()
    motes = []
    for i in range(N):
        motes.append(int(la[i]))

    motes.sort()
        
    sums =[]
    for i in range(N):
        if i == 0:
            sums.append(motes[i])
        else:
            sums.append(sums[i-1] + motes[i])
            
    for i in range(N):
        sums[i] = sums[i] + A
    
    cl = 0
    ad = 0
    adcounts = []
    clcounts = []
    for i in range(N):
        if i == 0:
            comp = A
        else:
            comp = sums[i-1]
            
            
        comp = comp + ad
        #print ("comp " + str(comp))
        adc = 0

        if (comp <= motes[i]) and (comp -1 <= 0):
            # impossible
            #print ("impo ")
            break
        #print ("comp " + str(comp) + "," + str(motes[i]))
        while comp <= motes[i]:
            ad = ad + comp- 1
            comp = comp + comp- 1
            cl = cl + 1
            adc = adc + 1
        
        if cl > N - i:
            break
        
        if cl > 0:
            cl = cl - 1
        
        adcounts.append(adc)
        clcounts.append(cl)
            

    lastcl0 = -1
    for i in range(len(clcounts)):
        if (clcounts[len(clcounts)-1 -i] == 0):
            lastcl0 = len(clcounts)-1 -i
            break
    # add
    opcount = 0
    #print("last cl0 " + str(lastcl0))
    for i in range(lastcl0+1):
        opcount = opcount + adcounts[i]
    
    # remove
    opcount = opcount + N - 1 - lastcl0

    
    print("Case #" + str(tc+1) + ": " + str(opcount))

