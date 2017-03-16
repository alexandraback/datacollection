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
    s = input()
    def solve():
        dic = {}
        starts =[]
        c = '1'
        while c not in dic:
            starts.append(c)
            dp = ['']*len(s)
            dic[c] = dp
            for i in range(len(s)):
                c = dijv(c,s[i])
                dp[i]=c

        period = len(starts) - starts.index(c)
        tail = len(starts) - period
        x=X-1
        lidx = x if x<tail else ((x-tail)%period)+tail
        
        last_start = starts[lidx]
        res = dic[last_start][len(s)-1] == '-1' #search for i,k,-1

        def get_next_idx(prev):
            prev += 1
            if prev == len(starts):
                prev = ((prev-tail)%period)+tail
            return prev

        def find(sch,start_idx,find_idx):
            assert(-1<start_idx<len(starts))
            idx = start_idx
            rem = min(X-start_idx,2*len(starts))

            while rem>0:
                ch = starts[idx]
                try:
                    f = dic[ch].index(sch,find_idx+1)
                    return (idx,f)
                except:
                    rem -= 1
                    idx = get_next_idx(idx)
                    find_idx = -1
            return (-1,-1)


        if res:
            found = find('i',0,-1)
            if found[0]>-1:
                found2 = find('k',found[0],found[1])
                res = found2[0]>-1
            else:
                res = False

        return 'YES' if res else 'NO'

    ans = solve()
    
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
