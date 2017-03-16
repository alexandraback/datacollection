import math
fin=open("frac.in","r")
fout=open("frac.out","w")
T=int(fin.readline())
for dummy in range(T):
    [K,C,S]=[int(x) for x in fin.readline().split()]
    fout.write('Case #'+str(dummy+1)+': ')
    if K==1:
        N=0
    else:
        N=(K**C-1)/(K-1)
    for j in range(K):
        fout.write(str(j*N+1)+' ')
    fout.write('\n')
fout.close()
fin.close()
