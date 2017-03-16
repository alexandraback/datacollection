import math


def findbetterblock(v,blocks,k):
    bestblockweight=99999
    bestblockn=-1
    a=0
    while a<len(blocks):
        if blocks[a]>v:
            if blocks[a]<bestblockweight and k[a]==0:
                bestblockn=a
                bestblockweight=blocks[a]
        a=a+1
    return bestblockn

def war(naomi,kens):
    #global naomi, kens, nscore,kscore
    nscore=0
    kscore=0
    k=[0 for i in range(0,len(naomi))]
    n=[0 for i in range(0,len(naomi))]
    a=0
    while a<len(naomi):
        g=findbetterblock(naomi[a],kens,k)
        if g==-1:
            nscore=nscore+1
        else:
            kscore=kscore+1
            k[g]=1
            
       

        a=a+1
    return nscore
    #print kscore
    #kens=k
    #naomi=n

def findguytoeliminate(bb):
    #find lowest naomi
    lowestn=-1
    lowest=9999
    a=0
    while a<len(bb):
        if bb[a][1]==0: #is naomi
            if bb[a][0]<lowest:
                lowest=bb[a][0]
                lowestn=a
        a=a+1
    a=0
    found=False
    higher=-1
    while a<len(bb):
        if bb[a][1]==1: #is a ken
            if bb[a][0]>bb[lowestn][0]:
                found=True
                higher=a
        a=a+1
    answer=[]
    answer.append(lowestn)
    answer.append(higher)
    return answer


def median(lst):
    lst.sort()
    a=len(lst)
    if a%2==0:
        return lst[a/2-1]
    else:
        return lst[a/2]

def kovermedian(naomi,kens):
    naomimedian=median(naomi)

    a=0
    for x in naomi:
        if x<naomimedian:
            a=a+1
    for y in kens:
        if y<naomimedian:
            a=a-1
    return a


def deceitfulwar(naomi,kens):
#    return len(naomi)-kovermedian(naomi,kens)

    
    global bb
    nscore=0
    kscore=0
    possiblescore=len(naomi)
    bb=[]
    a=0
    while a<len(naomi):
        bb.append([naomi[a],0])
        a=a+1
    a=0
    while a<len(naomi):
        bb.append([kens[a],1])
        a=a+1
    bb.sort()
    #find lowest naomi, check if under a ken
    #global bb
    n=0
    a=0
    ok=True
    while a<len(bb) and ok:

        if bb[a][1]==1:
            ok=False
        else:
            n=n+1    
        a=a+1
    return len(naomi)-n

    """
    ok=False
    while ok:
        rr=findguytoeliminate(bb)
        r=rr[1]
        w=rr[0]
        if r>-1:
            bb[r][1]=2 #means eliminated
            bb[w][1]=2
            possiblescore=possiblescore-1
        elif r==-1:
            ok=False
    print possiblescore
    """
    


filename='D-small-attempt2.in'
#filename='C-large.in'
ff=open(filename)
newfile=open('output.txt','wb')


t=int(ff.readline())
a=0




while a<t:

    n=int(ff.readline())
    naomi=ff.readline().split()
    kens=ff.readline().split()
    r=0
    while r<n:
        naomi[r]=float(naomi[r])
        kens[r]=float(kens[r])
        r=r+1

    
    d=str(deceitfulwar(naomi,kens))
    w=str(war(naomi,kens))
    newfile.write('Case #'+str(a+1)+": ")
    newfile.write(d+" ")
    newfile.write(w+"\r\n")

    

    #print a
    a=a+1


newfile.close()
