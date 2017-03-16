def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a 

def isTwoPower(n):
    b = 1
    for i in range(41):
        if n == b:
            return True
        b <<= 1
    return False

def simplify(P, Q):
    g = gcd(P, Q)
    return P // g, Q // g

dp = {}

def solve(P, Q):
    if (P, Q) in dp:
        return dp[P, Q]

    g = gcd(P, Q)

    P //= g
    Q //= g 

    if not isTwoPower(Q):
        dp[P, Q] = "impossible"
        return "impossible"

    if P == Q == 1:
        dp[P, Q] = 0
        return 0

    n = min(len(bin(Q)) - 3, solve(P + min(Q - P, P), Q) + 1)

    dp[P, Q] = n
    return n

T = int(input())

for tc in range(1, T + 1):
    P, Q = map(int, input().split('/'))
    print("Case #{}: {}".format(tc, solve(P, Q)))
