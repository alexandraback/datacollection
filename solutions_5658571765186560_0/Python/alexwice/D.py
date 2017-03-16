fi = open('A.in','r')
fo = open('A.out','w')
rr = lambda: fi.readline().replace('\n','')
rrI = lambda: int(rr())
rrM = lambda: map(int,rr().split())
rrS = lambda: rr().split()
#####

def solve(X,R,C):
    if R>C: R,C=C,R
    if (R*C)%X != 0: return 'RICHARD'
    if X >= 2*R+1: return 'RICHARD'
    if X > C: return 'RICHARD'
    if (X,R,C)==(4,2,4): return 'RICHARD'
    return 'GABRIEL'

#####
for T in xrange(rrI()):
    X,R,C = rrM()
    out = 'Case #%i: %s'%(T+1,solve(X,R,C))
    print out
    fo.write(out+'\n')
fo.close()
#####
