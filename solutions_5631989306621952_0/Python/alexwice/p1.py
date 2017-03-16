
#p1

def solve(S):
    ans = []
    for i in S:
        cand1 = [i] + ans
        cand2 = ans + [i]
        if cand1 > cand2:
            ans = cand1
        else:
            ans = cand2
    return "".join(ans)

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
