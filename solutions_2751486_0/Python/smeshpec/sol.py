VOW = ['a','e','i','o','u']

def solve(S, N, t):
    ans = 0
    v = 0
    L = len(S)
    for i in range(N):
        if S[i] in VOW:
            v += 1

    c = N
    X = -1
    n = L-N+1
    while n > 0:
        n -= 1
        if v == 0:
            Y = L-c
            X = c-N-X-1
            D = (1+Y)*(1+X)
            ans += D
            X = c-N

        if c <> L:
            if S[c] in VOW:
                v += 1
            if S[c-N] in VOW:
                v -= 1
        c += 1
    print "Case #%d: %d"%(t, ans)
    
def main():
    T = int(raw_input())
    for t in range(1, T+1):
        S, N = raw_input().split()
        N = int(N)
        solve(S, N, t)

main()