fin= open("A-large (2).in",'r')
fout=open("round1A_A.out",'w')
T = int(fin.readline())
for t in range(T):
    a = (fin.readline()).rstrip()
    s=[a[0]]
    for l in a[1:]:
        if l>=s[0]:
            s=[l]+s
        else:
            s=s+[l]

    fout.write("Case #"+str(t+1)+': ' +"".join(s)+'\n')
fout.close()
fin.close()
