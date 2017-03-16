import math
fin=open("frac.in","r")
fout=open("frac.out","w")
T=int(fin.readline())
for dummy in range(T):
    [K,C,S]=[int(x) for x in fin.readline().split()]
    fout.write('Case #'+str(dummy+1)+': ')
    if C*S<K:
        fout.write('IMPOSSIBLE\n')
    else:
        i=0
        cup=0
        while cup==0:
            N=1
            for j in range(C):
                N+=i*(K**j)
                i+=1
                if i>K-1:
                    cup=1
                i=min(i,K-1)
            fout.write(str(N)+' ')
        fout.write('\n')
fout.close()
fin.close()
