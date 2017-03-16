import sys
q = [['1','i','j','k'],\
['i','-1','k','-j'],\
['j','-k','-1','i'],\
['k','j','-i','-1']]

def dijv(c1,c2):
    def pos(c1):
        return q[0].index(c1[0] if c1[0]!='-' else c1[1])

    r = q[pos(c1)][pos(c2)]
    if len(c1)==len(c2):
        return r
    else:
        return '-'+r if len(r)==1 else r[1]

T=int(input())
for case_id in range(1,T+1):
    L,X = map(int,input().split())
    ijk = [input()] * X
    s = ''.join(ijk)
    def solve():
        dp = ['']*len(s)
        c = '1'
        for i in range(len(s)):
            c = dijv(c,s[i])
            dp[i]=c

        res = dp[len(s)-1] == '-1' #search for i,k,-1
        if res:
            try:
                dp.index('k',dp.index('i')+1)
            except:
                res = False
        return 'YES' if res else 'NO'

    ans = solve()
    
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
