
#p1
from collections import Counter
def solve(S):
    C = Counter(S)
    ans = [0]*10
    for flag,word,num in [ ("Z","ZERO",0),
                       ("X","SIX",6),
                       ("W","TWO",2),
                       ("G","EIGHT",8),
                       ("U","FOUR",4),
                       ("S","SEVEN",7),
                       ("H","THREE",3),
                       ("F","FIVE",5),
                       ("O","ONE",1),
                       ("I","NINE",9) ]:
        K = C[flag]
        ans[num] += K
        for w in word:
            C[w] -= K
        C += Counter()
    return "".join( chr(48+ix)*v for ix,v in enumerate(ans) )

########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        S = rr()
        zetaans = solve(S)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
