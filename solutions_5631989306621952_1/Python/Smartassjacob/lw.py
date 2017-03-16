import math
fin=open("lwin","r")
fout=open("lwout","w")
T=int(fin.readline())
for dummy in range(T):
    S=fin.readline().split()[0]
    T=S[0]
    S=S[1:]
    for x in S:
        if ord(x)>=ord(T[0]):
            T=x+T
        else:
            T=T+x
    fout.write('Case #'+str(dummy+1)+': '+T+'\n')
fin.close()
fout.close()

            
