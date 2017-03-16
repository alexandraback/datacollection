fi = open('A.in','r')
fo = open('A.out','w')
rr = lambda: fi.readline().replace('\n','')
rrI = lambda: int(rr())
rrM = lambda: map(int,rr().split())
rrS = lambda: rr().split()
#####

def solve(A):
    K,B = A
    K = int(K)
    B = map(int,list(B))
    standing = 0
    ct = 0
    shyadd = 0
    for i in B:
        if standing < ct:
            shyadd += ct-standing
            standing = ct
        standing += i
        ct += 1
    return shyadd


#####
for T in xrange(rrI()):
    A = rrS()
    out = 'Case #%i: %s'%(T+1,solve(A))
    print out
    fo.write(out+'\n')
fo.close()
#####

