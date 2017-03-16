path='C:\\CodeJam15\\Round1\\data\\'
name='A-small-attempt0'
raw=open(path+name+'.in', 'r')
wrt=open(path+name+'.out','w')
numTrials=int(raw.readline())
for i in range(numTrials):
    R, C, W= raw.readline().split()
    #print(maxShy, shyS)
    R=int(R)
    C=int(C)
    W=int(W)
    #for each row except the last
    rowCost=int(C/W)*(R-1)
    #the last row
    flag=(C%W)>0
    spe=int(C/W)+(W-1)
    if flag:
        spe+=1
    sol=rowCost+spe
    wrt.write('Case #'+str(i+1)+': '+str(sol)+'\n')
wrt.close()
