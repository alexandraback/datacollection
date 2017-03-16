import numpy
import math
import itertools
def Solve(B,M):
    #combinations r from 2 to B
    matrix=numpy.empty([B,B])
    Max=0;
    for In in range (0,B-1):
        #print In
        #print Cnk(B-2,In)
        Max+=Cnk(B-2,In)
    if Max<M:
        return ("IMPOSSIBLE",matrix)
    else:
        matrix[0,B-1]=1
        m=1
        if M==1:
            return ("POSSIBLE",matrix)
        else:
            for r in range(1,B+1):
                for comb in itertools.combinations(range(2,B),r):
                    comb=tuple([1])+comb+tuple([B])
                    m+=1
                    print comb,m
                    for i in range(len(comb)-1):
                        matrix[comb[i]-1,comb[i+1]-1]=1
                    if m>=M:
                        return ("POSSIBLE",matrix)
def Cnk(n,k):
    return math.factorial(n)/math.factorial(k)/math.factorial(n-k)
with open("B-small-attempt0.in") as handle,open("output.txt","w") as handle2:
    T=int(handle.readline().strip())
    for t in range(1,T+1):
        B,M=map(int,handle.readline().strip().split(" "))
        print B,M
        res,mat=Solve(B,M)
        if res=='IMPOSSIBLE':
            string="Case #%s: %s"%(t,res)
            print string
            handle2.write(string+"\n")
        else:
            string="Case #%s: %s"%(t,res)
            print string
            handle2.write(string+"\n")
            for line in matrix:
                string="".join(map(lambda x: str(int(x)),line))
                print string
                handle2.write(string+"\n")