import time
import itertools

# JeffB

debug = False

tStart = time.time()


fname = "C-small-attempt0"

fin = open(fname+".in","r")
flines = fin.readlines()
fin.close()

fout = open(fname+".out","w")

numcases = int(flines[0])   


for icase in range(numcases):

    rawline = flines[icase+1]
    line = rawline.split()

    N = int(line[0])
    nums = [int(line[i]) for i in range(1,N+1)]
    #print nums

    outstr ="Case #%d:" % (icase+1)
    print outstr
    fout.write("%s\n" % (outstr))

    oursums = dict()
    foundit = False
    for nelem in range(1,len(nums)): # don't need the +1
        for poss in itertools.combinations(nums,nelem):
            sumit = sum(poss)
            if sumit in oursums:
                # found it
                foundit = True
                outstr = " ".join([str(s) for s in oursums[sumit]])                
                print outstr
                fout.write("%s\n" % (outstr))
                outstr = " ".join([str(s) for s in poss])                
                print outstr
                fout.write("%s\n" % (outstr))
                break
            else:
                oursums[sumit] = poss
        if foundit:
            break
    if not foundit:
        outstr = "Impossible"
        print outstr
        fout.write("%s\n" % (outstr))
    
fout.close()

tEnd = time.time()

print "run time = %s" % (str((tEnd - tStart)))
