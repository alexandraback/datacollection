__author__ = 'Peter'

with open("A-large.out","w") as outF:
    with open("A-large.in","r") as inF:
        nt= int(inF.readline())
        for it in xrange(nt):
            r,c,w= map(int, inF.readline().split())
            count=0
            for ic in xrange(c):
                if (ic+1)%w==0:
                    count+=1
            count*=r
            if c%w!=0:
                count+=1
            count+=w-1
            print count
            outF.write("Case #%d: %d\n"%(it+1,count))