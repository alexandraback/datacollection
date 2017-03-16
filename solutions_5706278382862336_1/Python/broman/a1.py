inn=open("c:/downloads/in.in",'r')
rs=open("c:/downloads/rs.rs",'w')
T=int(inn.readline())
for I in range(T):
    s=(inn.readline()).split('/')
    P=int(s[0])
    Q=int(s[1])
    k=0
    while(Q%2==0):
        Q=Q//2
        k+=1
    if (P%Q)!=0:
        rs.write('Case #'+str(I+1)+': impossible\n')
        continue
    else:
        P=P//Q #=p/r so now original thingy is this P/2^k
        while(P//2>0):
            P=P//2
            k=k-1
        rs.write('Case #'+str(I+1)+': '+str(k)+'\n')
    
##    possible=True
##    if ((Q==1) & (P>0)):
##        possible=True
##    elif ((Q==1) & (P==0)):
##        possible=False
##    else:
##        gen=0
##        while(Q>1):
##            if Q%2!=0:
##                possible=False
##                break
##            else:
##                gen+=1
##                Q=Q/2
##    if not possible:
##        rs.write('Case #'+str(I+1)+': impossible\n')
##    else:
##        rs.write('Case #'+str(I+1)+': '+str(gen)+'\n')
inn.close()
rs.close()
