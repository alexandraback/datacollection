import math
fin=open("rfin","r")
fout=open("rfout","w")
T=int(fin.readline())
for dummy in range(T):
    A=[0 for x in range(2600)]
    N=int(fin.readline())
    for dummy2 in range(2*N-1):
        S=[x for x in fin.readline().split()]
        for x in S:
            A[int(x)]+=1
    fout.write("Case #"+str(dummy+1)+": ")
    for t in range(2600):
        if A[t]%2==1:
            fout.write(str(t)+" ")
    fout.write("\n")
fin.close()
fout.close()
