f = open('small.in')
g = open('small.out', 'w')

T = int(f.readline()[:-1])

D = {10: 10, 100: 29, 1000: 128}

def reach(n) :
    res = 0
    for d in range(2, len(str(n))+1) :
        m1 = (d-1)/2
        m2 = d-1-m1
        res += 10**m1 + 10**m2 - 1
    return res

def rev(n) : return int(str(n)[-1::-1])

def solveRec(n, c) :
    if c > N : return N
    if N in (n+1, rev(n)) : return c+1
    if rev(n) < n+1 : return solveRec(n+1, c+1)
    return min(solveRec(n+1, c+1), solveRec(rev(n), c+1))

def solve(n) :
    if n < 21 : return n
    if n % 10 == 0 : return solve(n-1) + 1
    if n < 100 : return 10 + n/10 + 1 + (n - 1 - 10*(n/10))
    mill = int('1' + '0'*(len(str(n))-1))
    c = reach(n)
    if n == mill : return c
    fh = str(n)[:rev(len(str(n))/2)]
    if fh != str(mill)[:len(str(fh))] :
        d = rev(fh)
        e = mill + d
        return c + d + 1 + n - rev(e)
    return c + n - mill

for case in range(T) :
    N = int(f.readline()[:-1])
    # map(int, f.readline()[:-1].split())
    res = solve(N)
    output = 'Case #' + str(case + 1) + ': ' + str(res)
    print output
    g.write(output + '\n')

f.close()
g.close()
