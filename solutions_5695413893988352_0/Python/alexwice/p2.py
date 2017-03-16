
#p1
def match(num,phrase,N):
    for i,j in zip(num, phrase):
        if i==j: continue
        if j=='?': continue
        return False
    return True

from itertools import product
digits = "0123456789"

def solve(A,B):
    N = len(A)
    best = 10**N
    pA = []
    pB = []
    for i in A:
        if i == '?': pA.append(digits)
        else: pA.append([i])
    for i in B:
        if i == '?': pB.append(digits)
        else: pB.append([i])
    for i in product(*pA):
        for j in product(*pB):
            dif=abs(int("".join(i))-int("".join(j)))
            if  dif < best:
                if match(i,A,N) and match(j,B,N):
                    best = dif
                    mem = i,j
    i,j = mem
    i = "".join(i)
    j = "".join(j)
    return i+' '+j
    """
    C = []
    J = []
    parity = 0 #parity -1 means C is behind
    for i,j in zip(A,B):
        if i=='?' and j=='?':
            if parity == 0:
                C.append("0")
                J.append("0")
            elif parity == -1:
                C.append("9")
                J.append("0")
            else:
                C.append("0")
                J.append("9")
        elif i=='?':
            C.append(j)
            J.append(j)
        elif j=='?':
            C.append(i)
            J.append(i)
        else:
            C.append(i)
            J.append(j)
    return "".join(C)+' '+"".join(J)"""

########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        A = rr().split()
        zetaans = solve(*A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
