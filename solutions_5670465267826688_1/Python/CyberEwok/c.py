path='C:\\CodeJam15\\QualificationRound\\data\\'
name='C-large'
raw=open(path+name+'.in', 'r')
wrt=open(path+name+'.out','w')

def mul(i,j):
    l='err'
    r='err'
    numNeg=0
    if i[0]=='-':
        numNeg+=1
        l=i[1]
    else:
        l=i[0]
    if j[0]=='-':
        numNeg+=1
        r=j[1]
    else:
        r=j[0]
    pre=""
    if numNeg%2==1:
        pre='-'
        
    if l=='1':
        return pre+r

    if r=='1':
        return pre+l

    if l=='i':
        if r=='i':
            numNeg+=1
            pre=""
            if numNeg%2==1:
                pre='-'
            return pre+'1'
        if r=='j':
            return pre+'k'
        if r=='k':
            numNeg+=1
            pre=""
            if numNeg%2==1:
                pre='-'
            return pre+'j'

    if l=='j':
        if r=='i':
            numNeg+=1
            pre=""
            if numNeg%2==1:
                pre='-'
            return pre+'k'
        if r=='j':
            numNeg+=1
            pre=""
            if numNeg%2==1:
                pre='-'
            return pre+'1'
        if r=='k':
            return pre+'i'

    if l=='k':
        if r=='i':
            return pre+'j'
        if r=='j':
            numNeg+=1
            pre=""
            if numNeg%2==1:
                pre='-'
            return pre+'i'
        if r=='k':
            numNeg+=1
            pre=""
            if numNeg%2==1:
                pre='-'
            return pre+'1'



print(mul('1','1'))
print(mul('-1','1'))
print(mul('1','-1'))
print(mul('-1','-1'))
print(mul('i','i'))
print(mul('j','j'))
print(mul('k','k'))

cor="YES"
fal="NO"
numTrials=int(raw.readline())
for i in range(numTrials):
    numChars, reps= (int(s) for s in raw.readline().split())
    reps=min(reps%4+8,reps)
    ijk=raw.readline().strip()*reps
    sol=['1','1','1','1']
    goal=['i','j','k','1']
    curPos=0
    #print(ijk)
    for c in ijk:
        sol[curPos]=mul(sol[curPos],c)
        if sol[curPos]==goal[curPos] and curPos<3:
            curPos+=1
    fin=fal
    if(curPos==3 and sol[3]=='1'):
        fin=cor
    wrt.write('Case #'+str(i+1)+': '+fin+'\n')
    #print(sol)
wrt.close()


    
