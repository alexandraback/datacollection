p = [10**7] * (10**6 + 10)
q = [(1, 1)]
while len(q) > 0:
    (n, old) = q.pop()
    if n >= len(p):
        continue
    if n <= 10:
        p[n] = n
        q.insert(0, (n+1, n))
    else:
        if p[old]+1 < p[n] or p[n-1]+1 < p[n]:
            q.insert(0, (int(str(n)[::-1]), n))
            q.insert(0, (n+1, n))
        p[n] = min(min(p[n], p[old]+1), p[n-1] + 1)
#        q.insert(0, (str(n)[::-1], n, p[n]))

def solve(N):
    if (N <= 20):
        return N
    elif int(str(N)[0]) == 1 and int('0' + str(N)[1:len(str(N))/2]) < 10:
        return p[len(str(N)) - 1] + int(str(N)[1:])
    else:
        if int(str(N)[len(str(N))/2:]) == 0:
            return solve(N-1) + 1
        N = str(N)
        return int((N[:len(N)/2])[::-1]) + int(N[len(N)/2:]) + p[len(N) - 1]


T = int(input())
for I in range(1, T+1):
    N = int(input())
    result = p[N]
    
    print("Case #%d: %d" % (I, result))
    
