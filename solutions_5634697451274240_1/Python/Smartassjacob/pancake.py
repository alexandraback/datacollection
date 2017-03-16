import math
fin=open("pan.in","r")
fout=open("pan.out","w")
T=int(fin.readline())
for dummy in range(T):
    fout.write("Case #"+str(dummy+1)+": ")
    s=fin.readline().strip()
    N=len(s)
    counter=0
    for i in range(N-1):
        if s[i]!=s[i+1]:
            counter+=1
    if s[N-1]=='-':
        counter+=1
    fout.write(str(counter)+'\n')
fout.close()
fin.close()
