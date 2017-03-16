#fin = file("A-small-attempt2.in", "rU")
#fout = file("A-small-attempt2.out", "w")
fin = file("A-large.in", "rU")
fout = file("A-large.out", "w")

nruns = int(fin.readline().strip())
for i in xrange(nruns):
    line = fin.readline().strip().split()
    mysize = int(line[0])
    nmotes = int(line[1])
    motes = map(int, fin.readline().strip().split())

    if mysize == 1: #best case to remove all
        strout = "Case #" + str(i+1) + ": " + str(nmotes) + "\n"
        fout.write(strout)
        continue

    motes.sort()

    #cumsum = mysize
    #modcount = 0
    remcost = (mysize,0) #current sum, current cost
    addcost = (mysize,0)
    for j in xrange(nmotes): #for each
        #print 'start ', addcost, remcost
        if motes[j] < remcost[0]:
            remcost = (remcost[0]+motes[j], remcost[1])
        else:
            remcost = (remcost[0], remcost[1]+1)
        if motes[j] < addcost[0]:
            addcost = (addcost[0]+motes[j], addcost[1])
        else: #can't absorb
            #absorb size one less than myself until over, or remove next one
            cumsum = addcost[0]
            canadd = cumsum - 1
            costtoadd = 1
            newsum = cumsum + canadd
            #print canadd, costtoadd, newsum
            while newsum <= motes[j]: #can't absorb
                canadd *= 2
                newsum += canadd
                costtoadd += 1
            #print 'afterloops ', canadd, costtoadd, newsum
            addcost = (newsum+motes[j], addcost[1]+costtoadd)

        #print addcost, remcost
        if addcost[1] <= remcost[1] and addcost[0] > remcost[0]:
            remcost = (addcost[0], remcost[1])
        #print addcost, remcost

    modcount = min(remcost[1], addcost[1])

    strout = "Case #" + str(i+1) + ": " + str(modcount) + "\n"
    #print strout
    fout.write(strout)
fin.close()
fout.close()
