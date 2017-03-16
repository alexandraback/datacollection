
#p1
from collections import Counter
def solve(N,A):
    #A is the row or column
    #find the missing one
    count = Counter()
    for i in A:
        count += Counter(i)
    ans = []
    for i in sorted(count):
        if count[i]%2: ans.append(i)
    return " ".join(map(str,ans))
    
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = [rrM() for _ in xrange(2*N-1)]
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
