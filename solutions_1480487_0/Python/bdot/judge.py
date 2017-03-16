import time
import itertools
import math

# JeffB

debug = False

tStart = time.time()


fname = "A-small-attempt3"
#fname = "judge"

fin = open(fname+".in","r")
flines = fin.readlines()
fin.close()

fout = open(fname+".out","w")

numcases = int(flines[0])   


for icase in range(numcases):

    rawline = flines[icase+1]
    line = rawline.split()

    N = int(line[0])
    nums = [float(line[i]) for i in range(1,N+1)]

    #print nums

    totsum = sum(nums)
    maxj = max(nums)
    rems = 0.0
    for x in range(len(nums)):
        rems += maxj - nums[x]

    if rems >= maxj or (rems == 0 and min(nums)==0):
        totrequired = maxj
    else:
        totrequired = maxj + ((totsum - rems) / len(nums))

    #for x in range(len(nums)):
    #    print (totrequired-nums[x]) / totsum
    
    outstr = ""
    for x in range(len(nums)):
        outstr += "%.6f" % (100*((totrequired-nums[x]) / totsum))
        if x < len(nums)-1:
            outstr += " "

    outstr ="Case #%d: %s" % (icase+1,outstr)
    print outstr
    fout.write("%s\n" % (outstr))
    
fout.close()

tEnd = time.time()

print "run time = %s" % (str((tEnd - tStart)))
