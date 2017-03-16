fin=open("input.txt",'r')
fout=open("output.txt",'w')
t=int(fin.readline())
for T in xrange(1,t+1):
    a,b,k=map(int,fin.readline().split())
    ans=0;
    for i in xrange(a):
        for j in xrange(b):
            if (i&j)<k:ans+=1                    
    fout.write("Case #"+str(T)+': '+str(ans)+"\n")
fin.close()
fout.close()
