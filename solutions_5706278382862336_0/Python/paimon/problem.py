import sys

sys.stdin = open('input')
sys.stdout = open('output', 'w')

deg = {2**i: i for i in range(40)}

def gcd(p, q):
    if p and q:
        if p > q:
            return gcd(p % q, q)
        else:
            return gcd(p, q % p)
    return p + q

def ht(p, q):
    if q not in deg or p == 0:
        return 'impossible'
    m = max(i for i in range(40) if 2**i <= p)
    return deg[q] - m

t = int(input())
answer = 'Case #{0}: {1}'
for i in range(t):
    p, q = map(int, input().split('/'))
    p, q = p/gcd(p, q), q/gcd(p, q)
    print(answer.format(i + 1, ht(p, q)))

sys.stdin.close()
sys.stdout.close()
