inn=open("c:/downloads/in.in",'r')
rs=open("c:/downloads/rs.rs",'w')
T=int(inn.readline())
for I in range(T):
    s=(inn.readline()).split()
    A=int(s[0])
    B=int(s[1])
    K=int(s[2])
    y=0
    for i in range(A):
        for j in range(B):
            if i&j<K:
                y+=1
    rs.write("Case #"+str(I+1)+": "+str(y)+"\n")
inn.close()
rs.close()
