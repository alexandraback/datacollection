import sys

def isall(d):
    for k,v in d.iteritems():
        if (not v):
            print "NOT:", k
            return False
    return True
    
with open("out.txt", "w") as fout:
    with open("A.in", "r") as f:
      n = int(f.readline())
      for i in xrange(n):
        k = int(f.readline())
        d = {}
        for x in range(10):
            d[x] = False        
        print "new:", k
        kk = k
        if k==0:
            res = "INSOMNIA"
        else:
            while not isall(d):
                for c in str(kk):
                    d[int(c)] = True
                kk += k
                print kk
            res = str(kk-k)
        fout.write("case #%d: %s\n" % (i+1, res))
            
    
