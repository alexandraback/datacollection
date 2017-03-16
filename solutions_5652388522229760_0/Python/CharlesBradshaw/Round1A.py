fin= open("A-small-attempt0 (1).in",'r')
fout=open("A-large-practice.out",'w')
T = int(fin.readline())
for t in range(T):
    a = int(fin.readline())
    if a==0:
         fout.write("Case #"+str(t+1)+': ' + 'INSOMNIA\n')
    else:
        digs = set(['0','1','2','3','4','5','6','7','8','9'])
        n=1;
        #print a
        while len(digs)>0:
            st = str(a*n)
            digs=digs.difference(set([i for i in st]))
            #print st, digs
            n = n+1
        #print 'done', st
        fout.write("Case #"+str(t+1)+': ' +st+'\n')
fout.close()
fin.close()
