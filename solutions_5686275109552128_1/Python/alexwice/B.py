fi = open('A.in','r')
fo = open('A.out','w')
rr = lambda: fi.readline().replace('\n','')
rrI = lambda: int(rr())
rrM = lambda: map(int,rr().split())
rrS = lambda: rr().split()
#####

def solve(D,A):
    #Suppose you eat k times.  How many times do you need to cut?
    maxi = 100000
    for eat in xrange(1,1001):
        t_ans = eat
        t_ans += sum([(x-1)/eat for x in A])
        if maxi > t_ans: maxi=t_ans
    return maxi

#####
for T in xrange(rrI()):
    D = rrI()
    A = rrM()
    out = 'Case #%i: %s'%(T+1,solve(D,A))
    print out
    fo.write(out+'\n')
fo.close()
#####

