import time

debug = False



tStart = time.time()

fname = "B-small-attempt0"

fin = open(fname+".in","r")
flines = fin.readlines()
fin.close()

fout = open(fname+".out","w")

besttotal = 0

numcases = int(flines[0])

def findbest(cenergy,maxenergy,recharge,tasks,curtotal):
    global besttotal # blech
    if not tasks:
        # base case
        if curtotal > besttotal:
            besttotal = curtotal
        return
    for spend in xrange(0,cenergy+1):
        findbest(min(maxenergy,cenergy-spend+recharge),maxenergy,recharge,tasks[1:],curtotal+spend*tasks[0])
    return
        
for icase in range(1,numcases+1):
   
    line1 = flines[2*icase-1].split()
    E = int(line1[0])
    R = int(line1[1])
    N = int(line1[2])
    line2 = flines[2*icase].split()
    plist = [int(line2[j]) for j in xrange(N)]
    print E, R, N
    print plist

    besttotal = 0
    findbest(E,E,R,plist,0)    
    result =  besttotal
    
    outstr = "Case #%d: %d" % (icase,result)
    print outstr
    fout.write("%s\n" % (outstr))
    
fout.close()

tEnd = time.time()

print "run time = %s" % (str((tEnd - tStart)))

    

            
