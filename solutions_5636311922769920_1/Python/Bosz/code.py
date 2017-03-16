
def createFractile(original,K, complexity):
    temp=original
    result=''
    for i in range(0,complexity-1):
        for tile in temp:
            if(tile=='L'):
                result+=original
            elif(tile=='G'):
                result+='G'*K
        temp = result
        result=''
    result= temp
    return result
    

def createAllPermutation(current,K,C):
    global allCombination
    if(len(current)>=K):
        #print current
        allCombination.append(createFractile(current,K,C))
        return
        

    createAllPermutation(current+'L',K,C)
    createAllPermutation(current+'G',K,C)
    
    return

T = int(raw_input())
allCombination =[]
#createAllPermutation('',3,2)
for s in allCombination : print s
for case in range(1,T+1):
    allCombination =[]
    K,C,S = [int(s) for s in raw_input().split(' ')]
    
    try:
    #if(K<=0 and C<=4):
        createAllPermutation('',K,C)
        #print allCombination
        totaltile = K**C
        
        countGold=0
        maxGold=0
        maxTile=-1
        maxGroup=[]
        for c in range(0,S):
            maxGold=0
            maxTile=-1
            for i in xrange(0,totaltile):
                countGold=0
                for j in xrange(0,len(allCombination)):
                    if(allCombination[j][i]=='G'):
                        countGold+=1
                        diff = 0
                        for m in maxGroup:
                            if (allCombination[j][m]=='G'):
                                diff=1
                        countGold-=diff
                if(countGold>maxGold):
                    maxTile = i
                    maxGold =countGold
            if(maxTile>-1): maxGroup.append(maxTile)
        text= ''.join([str(int(u)+1)+' ' for  u in maxGroup])
        countGold=0
        for i in xrange(0,len(allCombination)):
            if(countGold>0):
                text = 'IMPOSSIBLE'
                break
            else :
                countGold=0
                for j in xrange(0,totaltile):
                    if(allCombination[i][j]=='G'and j not in maxGroup and countGold==0):
                        countGold=1
                    elif(allCombination[i][j]=='G'and j  in maxGroup):
                        countGold=-1
                        break
                
        print 'Case #{}: {}'.format(case,text.strip())
    except :
    #else:
        #print 'Case #{}: {}'.format(case,'IMPOSSIBLE')
        if not (S>=K-(C-1)):
            print 'Case #{}: {}'.format(case,'IMPOSSIBLE')
        elif (C==1):
            text=''
            for i in range(1,S+1):
                    text+=(str(i)+' ')
            print 'Case #{}: {}'.format(case,text.strip())
        else :
            num=2
            total =K**C
            next_add = K+1
            text=''
            for i in range(0,S):
                if(num<=total):
                    text+=(str(num)+' ')
                    num+=next_add
                else: break
            print 'Case #{}: {}'.format(case,text.strip())
        
            
