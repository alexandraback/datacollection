fin= open("B-small-attempt0.in",'r')
fout=open("round1B.out",'w')
T = int(fin.readline())
for t in range(T):
    a = (fin.readline()).rstrip()
    
    p = [i=='+'for i in a]
    p=p+[True]
    #print a,p
    f = [p[i]^p[i+1] for i in range(len(p)-1)]
    #print sum(f)

    fout.write("Case #"+str(t+1)+': ' +str(sum(f))+'\n')
fout.close()
fin.close()
