from datetime import datetime
import copy

#Input
fName = raw_input('Enter Filename of Input:\n')
with open(fName) as f:
    inp = [line.rstrip() for line in f]
#Output
timestamp = datetime.now().strftime("%H.%M.%S")
out = open('d'+timestamp+'.out', 'w')

#Stuff
caseCount = int(inp[0])
for case in range(1,caseCount+1):
    line = 1+3*(case-1)
    amt = int(inp[line])
    nBks = sorted([float(n) for n in inp[line+1].split()])
    ndBks = copy.deepcopy(nBks)
    kBks = sorted([float(n) for n in inp[line+2].split()])
    kdBks = copy.deepcopy(kBks)
    nPts = 0
    ndPts = 0

    for removed in range(amt):
        #Deceit
        aLoss = False
        for index in range(amt-removed):
            if(kdBks[index]>ndBks[index]):
                aLoss = True
                break
        if aLoss:
            kdBks.pop(amt-removed-1)
            ndBks.pop(0)
        else:
            ndPts = amt-removed
            break

    for removed in range(amt):
        #Normal
        aLoss = False
        nChoice = nBks.pop(amt-removed-1)
        if kBks[amt-removed-1]>nChoice:
            for index in range(amt-removed):
                if kBks[index]>nChoice:
                    kChoice = kBks.pop(index)
                    break
        else:
            kBks.pop(0)
            nPts += 1
        
            

    out.write('Case #%d: %d %d\n'%(case,ndPts,nPts))
out.close()
