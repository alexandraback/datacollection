import time
import math

# JeffB

debug = False

tStart = time.time()


fname = "A-large"

fin = open(fname+".in","r")
flines = fin.readlines()
fin.close()

fout = open(fname+".out","w")

numcases = int(flines[0])   


for icase in range(numcases):
    def docalc(initcost,curp):
        goodstroke = bigB-curp 
        badstroke = 2*bigB - curp + 1
        cost = float(initcost) + probscorrect[curp]*goodstroke + (1.0-probscorrect[curp])*badstroke
        #print "g=%d,b=%d,i=%f,c=%f" % (goodstroke,badstroke,initcost,cost)
        return cost
    
    rawfirstline = flines[2*icase+1]
    rawsecondline = flines[2*icase+2]
    firstline = rawfirstline.split()
    bigA = int(firstline[0])
    bigB = int(firstline[1])
    secondline = rawsecondline.split()
    probs = [float(secondline[x]) for x in range(bigA)]
    #print "Case %d" % (icase+1)


    probscorrect = [0.0]*(bigA)
    probscorrect[0] = probs[0]
    for i in range(1,bigA):
        probscorrect[i] = probscorrect[i-1]*probs[i]
    #print probscorrect

    pool = []
    for curp in range(bigA-1,-1,-1):
        #print "curp = %d" % curp
        pool.append(docalc(bigA-curp-1,curp))
    pool.append(bigA+bigB+1) # Full backspace
    pool.append(bigB+2)      # immediate entry

    ourval = min(pool)

    outstr = "Case #%d: %.6f" % (icase+1,ourval)
    print outstr
    fout.write("%s\n" % (outstr))

fout.close()

tEnd = time.time()

print "run time = %s" % (str((tEnd - tStart)))
