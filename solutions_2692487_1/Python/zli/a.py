for case in range(input()):
    print "Case #"+str(case+1)+":",
    A,N=map(int,raw_input().split())
    motes=map(int,raw_input().split())
    motes.sort()
    #print A,motes
    for i,mote in enumerate(motes):
        if mote<A:
            A += mote
        else:
            motes = motes[i:]
            break
    if A>motes[-1]:
        motes = []

    def cost(A,j):
        num = 0
        #print A
        for i, mote in enumerate(motes):
            if i>=j: break
            while A <= mote:
                A = 2*A - 1
                num += 1
                #print A,mote
            A += mote
        #print num,len(motes)-j,j
        return num+len(motes)-j

    #print A,motes
    if A<=1:
        mincost = len(motes)
    else:
        mincost = ""
        for i in xrange(len(motes)+1):
            mincost = min(mincost, cost(A,i))
    print mincost

