filename  = "C-large.in"
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
for Ca in range(T):
    [J, P, S, K]=[int(j) for j in f.readline().split()]
    if J*P*S<J*P*K:
        ret =J*P*S
        rets =[[str(i+1),str(j+1),str(k+1)] for i in range(J) for j in range(P) for k in range(S)]
        rets = '\n'.join([' '.join(i) for i in rets])
    else:
        ret =J*P*K
        rets =[[str(i+1),str(j+1),str((i+j+k-3)%S+1)] for i in range(J) for j in range(P) for k in range(K)]
        rets = '\n'.join([' '.join(i) for i in rets])
    print("Case #"+str(Ca+1)+": "+str(ret)+"\n"+rets)
    out.write("Case #"+str(Ca+1)+": "+str(ret)+"\n"+rets+"\n")
f.close()
out.close()
