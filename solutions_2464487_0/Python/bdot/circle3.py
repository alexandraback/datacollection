import time

debug = False



tStart = time.time()

fname = "A-small-attempt0"

fin = open(fname+".in","r")
flines = fin.readlines()
fin.close()

fout = open(fname+".out","w")

numcases = int(flines[0])

def arithsum(n,a1):
    return n*(a1+a1+4*(n-1))/2



for icase in range(1,numcases+1):
   
    line = flines[icase].split()
    r = int(line[0])
    availt = int(line[1])

    #print r, availt

    curt = availt
    count = 1

    firstcircle = (r+1)**2 - r**2
    n = 2
    while arithsum(n,firstcircle) < availt:
        n = n * 2
    #print 'result is between %d and %d' % (n/2,n)
    # ok bounded between n/2 and n, now converge
    minbound = n/2
    maxbound = n
    while True :
        #print minbound, maxbound
        if maxbound - minbound == 1:
            if arithsum(maxbound,firstcircle) == availt:
                finaln = maxbound
            else:
                finaln = minbound
            break
        guess = (minbound + maxbound) / 2
        res = arithsum(guess,firstcircle)
        if res > availt:
            maxbound = guess
        elif res < availt:
            minbound = guess
        else:
            finaln = guess
            break    
        
    result = finaln
    
    outstr = "Case #%d: %d" % (icase,result)
    print outstr
    fout.write("%s\n" % (outstr))
    
fout.close()

tEnd = time.time()

print "run time = %s" % (str((tEnd - tStart)))

    

            
