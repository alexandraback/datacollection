def solve(n,m):
    if (m > 2**(n-2)):
        print "IMPOSSIBLE"
        return
    print "POSSIBLE"
    s = set()
    m-=1
    for i in range(2,n):
        for j in range(2,i):
            s.add((i,j))
        s.add((i,n))
    b = bin(m)[2:]; b = b[::-1]
    b = "xx"+b
    for i in range(2,len(b)):
        if (b[i] == '1'):
            s.add((1,i))
    s.add((1,n))
    for i in range(1,n+1):
        cur = ""
        for j in range(1,n+1):
            if ((i,j) in s):
                cur += "1"
            else:
                cur += "0"
        print cur

t = input()
for qq in range(t):
    n,m = map(int,raw_input().split())
    print "Case #%d:"%(qq+1),
    solve(n,m)
