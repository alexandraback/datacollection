path='C:\\CodeJam15\\QualificationRound\\data\\'
name='D-small-attempt0'
raw=open(path+name+'.in', 'r')
wrt=open(path+name+'.out','w')
numTrials=int(raw.readline())
gWin='GABRIEL'
rWin='RICHARD'
for i in range(numTrials):
    X,R,C=(int(val) for val in raw.readline().split())
    div=int((R*C)/X)
    short=int((X+1)/2)
    if X>6:
        sol=rWin
    elif not div*X==R*C:
        sol=rWin
    elif short>min(R,C):
        sol=rWin
    elif X>=4 and short>=min(R,C):
        sol=rWin
    else:
        sol=gWin
    wrt.write('Case #'+str(i+1)+': '+sol+'\n')
wrt.close()



    
