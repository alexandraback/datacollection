#!/usr/bin/env python
import math
T=int(raw_input().strip())

output='''1 1
2 4
3 9
11 121
22 484
101 10201
111 12321
121 14641
202 40804
212 44944
1001 1002001
1111 1234321
2002 4008004
10001 100020001
10101 102030201
10201 104060401
11011 121242121
11111 123454321
11211 125686521
20002 400080004
20102 404090404
100001 10000200001
101101 10221412201
110011 12102420121
111111 12345654321
200002 40000800004
1000001 1000002000001
1001001 1002003002001
1002001 1004006004001
1010101 1020304030201
1011101 1022325232201
1012101 1024348434201
1100011 1210024200121
1101011 1212225222121
1102011 1214428244121
1110111 1232346432321
1111111 1234567654321
2000002 4000008000004
2001002 4004009004004'''

table=[int(x.split()[1]) for x in output.split('\n')]

def ispalindrome(i):
    s=str(i)
    l, h=0, len(s)-1
    while l<h:
        if s[l]!=s[h]:
            return False
        l+=1
        h-=1
    return True

for i in range(1, T+1):
    N, M = raw_input().strip().split()
    N, M = int(N), int(M)
    total=0
    #n=int(math.pow(N, 0.5))
    #m=int(math.pow(M, 0.5))
    #if n*n<N:n=n+1
    #if m*m>M:m=m-1
    #for j in xrange(n, m+1):
    #    if ispalindrome(j):
    #        k=j*j
    #        if ispalindrome(k):
    #            print j,k
    #            total+=1
    
    for j in range(len(table)):
        if table[j] >= N and table[j]<=M:
            total+=1

    print 'Case #%d: %d' % (i, total)

