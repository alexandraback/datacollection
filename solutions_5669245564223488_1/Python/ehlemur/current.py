def unique(s):
    r = s[0] 
    for i in range(1, len(s)):
        if s[i] != r[-1]:
            r += s[i]
    return r

def solve(A):
    S = {}

    R = {}
    L = {}

    for s in A:
        if len(s) == 1:
            S[s[0]] = S.get(s[0], 0) + 1
        else:
            if s[0] in R:
                return 0
            else:
                R[s[0]] = s

            if s[-1] in L:
                return 0
            else:
                L[s[-1]] = s

    for s in R.values():
        for i in range(1, len(s) - 1):
            if s[i] in R or s[i] in L:
                return 0

    ways = 1
    for c in S.keys():
        ways = (ways * f[S[c]]) % MOD
        if c not in R and c not in L:
            R[c] = L[c] = c

    n = 0
    while len(R) > 0:
        _, s = R.popitem()
        del L[s[-1]]

        while s[-1] in R:
            s += R.pop(s[-1])
            del L[s[-1]]
        
        while s[0] in L:
            s = L.pop(s[0]) + s
            del R[s[0]]

        if len(s) > 1 and s[0] == s[-1]:
            return 0

        n += 1
    
    ways = (ways * f[n]) % MOD
    
    return ways

MOD = int(1e9 + 7)

f = [1]
for i in range(1, 105):
    f.append((f[-1] * i) % MOD)


T = int(input())

for tc in range(1, T + 1):
    n = int(input())
    A = list(map(unique, input().split()))

    print("Case #{}: {}".format(tc, solve(A)))
