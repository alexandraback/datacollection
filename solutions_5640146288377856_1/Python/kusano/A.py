def check(C,W,B):
    c = B.count(1)
    for x in range(C-W+1):
        if B[x:x+W].count(1)==c and B[x:x+W].count(-1)==0:
            return True
    return False

def BT(C,W,B):
    Bt = tuple(B)
    if Bt in memo:
        return memo[Bt]

    ans = 9999
    T = [0]*C
    for x in range(C-W+1):
        if B[x:x+W].count(1)==B.count(1) and B[x:x+W].count(-1)==0:
            for i in range(x,x+W):
                T[i] += 1
    mt = -1
    x = -1
    for i in range(C):
        if B[i]==0 and T[i]>mt:
            mt = T[i]
            x = i

    ans = 0

    B[x] = -1
    if check(C,W,B):
        ans = max(ans, BT(C,W,B)+1)
    B[x] = 0

    if ans==0:
        B[x] = 1
        if B.count(1)==W:
            ans = max(ans, 1)
        else:
            ans = max(ans, BT(C,W,B)+1)
        B[x] = 0

    memo[Bt] = ans
    return ans

def solve(R,C,W):
    global memo
    B = [0]*C
    memo = {}
    ans = BT(C,W,B)
    return ans + (R-1)*((C+2*W-2)/(2*W-1))

for t in range(input()):
    R,C,W = map(int, raw_input().split())
    print "Case #%s: %s"%(t+1, solve(R,C,W))
