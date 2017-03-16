fin = open('C.in', 'r')
fout = open('file.out', 'w')
n = fin.readline()
    
for l in range(int(n)):
    j,p,s,k = map(int,fin.readline().split())
    #print j,p,s,k
    if k >= s:
        fout.write("Case #%d: %d\n"%(l+1,j*p*s))
        for i in range(j):
            for l in range(p):
                for m in range(s):
                    fout.write("%d %d %d\n"%(i+1,l+1,m+1))
    else:
        #print 'ping'
        fout.write("Case #%d: %d\n"%(l+1,j*p*k))
        for i in range(j):
            for l in range(p):
                for m in range(k):
                    fout.write("%d %d %d\n"%(i+1,l+1,(i + l + m+1)%s+1))
           
    
fin.close()
fout.close()
