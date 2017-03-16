path='C:\\CodeJam15\\QualificationRound\\data\\'
raw=open(path+'A-small-attempt0.in', 'r')
wrt=open(path+'out.txt','w')
numTrials=int(raw.readline())
for i in range(numTrials):
    maxShy, shyS= raw.readline().split()
    #print(maxShy, shyS)
    maxF=0
    cumT=0
    for j in range(int(maxShy)+1):
        maxF=max(maxF,j-cumT)
        cumT=cumT+int(shyS[j])
        #print(j)
    wrt.write('Case #'+str(i+1)+': '+str(maxF)+'\n')
wrt.close()
