#run with python2 m1.py <input >output on linux

cases = input()

for case in range(cases):
    #Get input
    am = raw_input().split(" ")
    armin = int(am[0])
    mote = int(am[1])
    motes = []
    counts = []
    for m in raw_input().split(" "):
        motes.append(int(m))
        counts.append(0)
    #special case
    if armin==1:
        print "Case #%s: %s" %(case+1, mote)
        continue 
    #without removing   
    motes.sort()
    for i in range(mote):
        if i!=0:
            counts[i] += counts[i-1]
        if armin>motes[i]:
            armin += motes[i]
        else:
            while armin <= motes[i]:
                armin = armin*2-1
                counts[i] += 1
            armin += motes[i]
    cost = counts[mote-1]
    for i in range(mote):
        if cost >= counts[i] + mote-i -1:
            cost = counts[i] + mote-i -1
    if cost>mote:
        cost = mote     
    print "Case #%s: %s" %(case+1, cost)
