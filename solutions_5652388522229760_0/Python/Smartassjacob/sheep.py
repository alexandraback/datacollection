import math
fin=open("sheepsmall.in","r")
fout=open("sheep.out","w")
comp=set('1234567890')
T=int(fin.readline())
for x in range(T):
    fout.write("Case #"+str(x+1)+": ")
    N=int(fin.readline())
    if N==0:
        fout.write("INSOMNIA\n")
    else:
        i=0
        s=set()
        while s!=comp:
            i=i+1
            s=s.union(set(str(i*N)))
        fout.write(str(i*N)+"\n")
fout.close()
fin.close()


