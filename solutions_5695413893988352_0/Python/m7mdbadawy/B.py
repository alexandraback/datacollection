t = int(raw_input())

def solve(s1,s2,ind,p):
    if (ind == len(s2) and p == 1):
        return (abs(int("".join(s1)) - int("".join(s2)) ),[x for x in s1],[x for x in s2])
    n_ind = ind
    if p == 1:
        n_ind += 1
    s = s1
    #print ind,s1,s2,p
    if (p==1): s = s2
    if (ind == len(s2) and p==0) or s[ind] != '?' : return solve(s1,s2,n_ind,1-p)
    ans = (10**9,[],[])
    for i in xrange(10):
        s[ind] = str(i)
        ans = min(ans,solve(s1,s2,n_ind,1-p))
        s[ind] = "?"
    return ans
        

for cn in xrange(t):
    s1,s2 = raw_input().split()
    t = solve([x for x in s1],[x for x in s2],0,0)
    print "Case #%d: %s %s" %(cn+1,"".join(t[1]),"".join(t[2]))
