T = int(raw_input())
for t in xrange(T):
    mydic=dict()
    N=int(raw_input())
    for j in xrange(2*N-1):
        tempreading=map(int, raw_input().split())
        for i in tempreading:
            mydic[i]=mydic.get(i,0)+1
    myanswer=[]
    for key,value in mydic.iteritems():
        if value%2==1:
            myanswer.append(key)
    myanswer=sorted(myanswer)
    #print myanswer
    #print("Case #{}: {}".format(t+1, myanswer))
    print "Case #"+str(t+1)+":",
    for i in myanswer[:-1]:
        print i,
    print myanswer[-1]

