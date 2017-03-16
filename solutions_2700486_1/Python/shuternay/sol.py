import math

def func(k, n, m):
    #print(k, n, m)

    if n <= 0 or n < k:
        return 0

    if n >= 2 * m - 1:
        return 1

    if k == m:
        if n >= 2*m-1:
            return 1
        else:
            return 0

    if n > m - 1:
        t = n - m + 1
        n -= 2 * t
        m -= t
        k -= t
    
    if k <= 0:
        return 1

    ans = c = math.factorial(n) // math.factorial(k) // math.factorial(n-k)

    for i in range(k+1, n+1):
        c *= (n - i + 1) / i
        ans += c

    ans /= 2**n
    return ans

FIN = open("input.txt", "r")
FOUT = open("output.txt", "w")

T = int(FIN.readline().split()[0])

for t in range(1, T+1):
    inp = FIN.readline().split()
    n = int(inp[0])
    x = abs(int(inp[1]))
    y = int(inp[2])
    line = int( (x+y) / 2 + 1 )

    n -= int( (4 * line - 6) * (line-1) / 2 )
    m = 2 * line - 1
    k = y + 1

    print("Case #", t, ": ", func(k, n, m), sep="", file=FOUT)

    


