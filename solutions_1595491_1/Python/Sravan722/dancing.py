f=open("B-large.in","r")
lists=f.readlines()
tests=int(lists[0])
i=1
while i<=tests:
    values=lists[i].split(' ')        
    intval=[int(each) for each in values]
    num=intval[0]
    surp=intval[1]
    maxval=intval[2]
    k=3
    total=0
    if maxval!=0:
        while num>0:
            if intval[k]==0:
                k=k+1
                num=num-1
                continue
            x=intval[k]%3
            divval=intval[k]/3
            if x==1:            
                if maxval<=divval+1:
                    total+=1
            elif x==0:            
                if maxval<=divval:
                    total+=1
                elif maxval<=divval+1:
                    if surp>0 and (intval[k]>=2 and intval[k]<=28):
                        surp-=1
                        total+=1
            elif x==2:
                if maxval<=divval+1:
                    total+=1
                elif maxval<=divval+2:
                    if surp>0 and (intval[k]>=2 and intval[k]<=28):
                        surp-=1
                        total+=1
            k=k+1
            num=num-1
    else:
        total=num
    print "Case #%d: %d" %(i,total)
    i=i+1
