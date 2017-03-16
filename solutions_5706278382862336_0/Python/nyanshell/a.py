
def dfs(l, p):
    if l == 40:
        if p == q and l == 40:
            return l
        return False
    #print (p, q, l)
    if p*2 == q:
        return l
    if p*2 > q and dfs(l+1, p*2 - q):
        return l
    elif p*2 < q:
        return dfs(l+1, p*2)
    return False

for i in range(0, int(input())):
    pq = str(input())
    p = int(pq.split("/")[0])
    q = int(pq.split("/")[1])
    ans = dfs(1, p)
    if not ans:
        ans = "impossible"
    print ("Case #%d:" % (i+1), ans)
