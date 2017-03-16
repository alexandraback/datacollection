def chunks(l, n):
    """ Yield successive n-sized chunks from l.
    """
    for i in xrange(0, len(l), n):
        yield l[i:i+n]

def value(A,B):
    #print A,B
    if not A or not B:
        return 0
    maxval=value(A[1:],B[0:])
    val0=0
    #remval=value(A[1:],B[0:])
    val0=0
    #Use up to and including part of i
    for i in xrange(len(B)):
        if B[i][1]==A[0][1] and A[0][0]:
            newval=min(A[0][0],B[i][0])
            val0+=newval
            #A[0][0]-=newval
            #B[i][0]-=newval
            A[0]=(A[0][0]-newval,A[0][1])
            B[i]=(B[i][0]-newval,B[i][1])
            remval=value(A[1:],B[i:])
            #print i,A,B,val0,remval
            maxval=max(maxval,val0+remval)
        #val0=sum(num for num,typ in B[:i] if typ==A[0][1])
    return maxval

for case in range(input()):
    print "Case #"+str(case+1)+":",
    N,M=map(int,raw_input().split())
    A=list(chunks(map(int,raw_input().split()),2))
    B=list(chunks(map(int,raw_input().split()),2))
    A=map(tuple,A)
    B=map(tuple,B)
    #print A,B
    print value(A,B)
    """
    A+=[(0,-1)]*(3-len(A))
    maxval=0
    for i in xrange(len(B)+1):
        val0=sum(num for num,typ in B[:i] if typ==A[0][1])
        for i0 in xrange(0,i):
            
        val0=min(A[0][0],sum(num for num,typ in B[:i] if typ==A[0][1]))
        for j in xrange(i,len(B)+1):
            print i,j,
            val1=min(A[1][0],sum(num for num,typ in B[i:j] if typ==A[1][1]))
            val2=min(A[2][0],sum(num for num,typ in B[j:] if typ==A[2][1]))
            print val0,val1,val2,val0+val1+val2
            maxval=max(maxval,val0+val1+val2)
    print maxval
    """
