inFile = open('a.in', 'r')
outFile = open('a.out', 'w')

T = int(inFile.readline())
for case in range(1, T+1):
    [n, m] = map(int, inFile.readline().split())
    p = map(float, inFile.readline().split())
    ans = m+2
    pt = 1.0
    for i in range(n, -1, -1):
        ans = min(2*m-n+2 + 2*i - pt*(m+1), ans)
        if i > 0:
            pt = pt * p[n-i]
    outFile.write('Case #{0}: {1}\n'.format(case, ans))

inFile.close()
outFile.close()
    
