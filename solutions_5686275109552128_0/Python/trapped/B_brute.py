# stupid brute: warning bad code ahead!!

T = int(raw_input())

memo = {}
def mintime(h):
    h = sorted(h)
    if max(h) <= 3: return max(h)
    th = tuple(h)
    if th in memo: return memo[th]
    #print th
    h1 = []
    has2 = has3 = False
    for i in range(len(h)):
        if h[i] > 1: 
            if not has2 and h[i] == 2: has2 = True
            elif h[i] == 2: continue
            if not has3 and h[i] == 3: has3 = True
            elif h[i] == 3: continue
            h1.append(h[i]-1)
    if len(h1) > 0: 
        mint = 1+mintime(h1)
    else: 
        mint = max(h)
    for i,x in enumerate(h):
        if x < 4: continue
        for c in range(2,x//2 + 1):
            t2 = 1+mintime(h[:i]+[h[i]-c,c]+h[i+1:])
            if t2 < mint: mint = t2
    memo[th] = mint
    return mint
                 
    

for t in range(1,T+1):
    D = int(raw_input())
    h = map(int, raw_input().split())
    print "Case #%d: %d"%(t,mintime(h))
