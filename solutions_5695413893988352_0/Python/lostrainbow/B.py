def traverse(C,J,c,j):
    if len(C)==0:
        c.append('')
        j.append('')
    else:
        traverse(C[1:],J[1:],c,j)
        if C[0]=='?' and J[0]=='?':
            for i in range(len(c)):
                ctemp=c.pop(0)
                jtemp=j.pop(0)
                for i in range(48,58):
                    for k in range(48,58):
                        c.append(chr(i)+ctemp)
                        j.append(chr(k)+jtemp)
        elif C[0]=='?':
            for i in range(len(c)):
                ctemp=c.pop(0)
                jtemp=j.pop(0)
                for i in range(48,58):
                    c.append(chr(i)+ctemp)
                    j.append(J[0]+jtemp)
        elif J[0]=='?':
            for i in range(len(c)):
                ctemp=c.pop(0)
                jtemp=j.pop(0)
                for i in range(48,58):
                    c.append(C[0]+ctemp)
                    j.append(chr(i)+jtemp)
        else:
            for i in range(len(c)):
                ctemp=c.pop(0)
                jtemp=j.pop(0)
                c.append(C[0]+ctemp)
                j.append(J[0]+jtemp)
                    
        
            
        
        
        
        
        

def solve(IF):
    temp=IF.readline().split()
    C=temp[0]
    J=temp[1]
    c=[]
    j=[]
    bd=10**19
    traverse(C,J,c,j)
    bn=10**19
    dtable=[]
    ctable=[]
    for i in range(len(c)):
        dtemp=abs(int(c[i])-int(j[i]))
        dtable.append(dtemp)
        bd=min(bd,dtemp)
    for i in range(len(c)):
        ctemp=int(c[i])
        ctable.append(ctemp)
        if bd==abs(dtable[i]):
            bn=min(bn,ctemp)
    for i in range(len(c)):
        if bd==dtable[i] and bn==ctable[i]:
            return c[i]+' '+j[i]
    
    
    
    
    
    
    
    
    
    
    
    
IF=open('B-small-attempt1.in','r')
OF=open('output','w')
temp=IF.readline()
CaseN=int(temp)


for i in range(1, CaseN+1):
    pretext='Case #{}: '.format(i)
    ans=solve(IF)
    if i<CaseN:
        ans=ans+'\n'
    OF.write(pretext+ans)
    
    
    
IF.close()
OF.close()
