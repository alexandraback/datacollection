t=input()
for case in range(t):
    n=input()
    line=raw_input().split()
    naiomi=[]
    for l in line:
        naiomi.append(float(l))
    ken=[]
    line=raw_input().split()
    for l in line:
        ken.append(float(l))
    #print naiomi,ken
    naiomi.sort()
    ken.sort()
    naiomi_idx=0
    ken_idx=len(ken)-1
    ken_idx_min=0
    #print naiomi,ken
    naiomi_win=0
    ken_win=0
    while(naiomi_idx<len(naiomi)):
        if naiomi[naiomi_idx]>ken[ken_idx_min]:
            naiomi_win+=1
            naiomi_idx+=1
            ken_idx_min+=1
        elif (naiomi[naiomi_idx]>ken[ken_idx]):
            naiomi_win+=len(naiomi)-naiomi_idx
            break
        else:
            ken_win+=1
            ken_idx-=1
            naiomi_idx+=1
    #print naiomi_win,ken_win
    naiomi_idx=0
    naiomi_win2=0
    ken_win2=0
    while (naiomi_idx<len(naiomi)):
        flag=0
        for i in range(len(ken)):
            if ken[i]>naiomi[naiomi_idx]:
                ken_win2+=1
                naiomi_idx+=1
                ken[i]=0
                flag=1
                break
        if not flag:
            naiomi_win2+=len(naiomi)-naiomi_idx
            break
    #print naiomi_win2,ken_win2
    print 'Case #%d: %d %d'%(case+1,naiomi_win,naiomi_win2)