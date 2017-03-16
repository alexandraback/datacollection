fi=open('A-small-attempt1.in','r')
data=fi.readlines()
fi.close()
fo=open('out.txt','w')
t=int(data[0])
for i in range(1,t+1):
    tmp=data[i].split()
    n=int(tmp[0])
    s=0
    for j in range(1,n+1):
        s+=int(tmp[j])
    k=2.0*s/n
    tt=s
    tn=0
    for j in range(1,n+1):
        if int(tmp[j])<k:
            tt+=int(tmp[j])
            tn+=1
    tt=(tt+0.0)/tn
    fo.write('Case #%d:'%i)
    for j in range(1,n+1):
        if int(tmp[j])>=k:
            fo.write(' 0.000000')
            continue
        fo.write(' %f'%((tt-int(tmp[j]))*100.0/s))
    fo.write('\n')
fo.close()
