p = 0
INF = 10000000
def check(arr):
    global p

    flag1 = flag2 = flag3 = flag4 = 0
    for a,b,c in arr:
        
        con1 =  a-b == 2 or b-c == 2 or a-c == 2
        con2 =  a >= p or b >= p or c >= p

        
        flag1 |= con1
        flag2 |= not con1

        flag3 |= not con1 and con2
        flag4 |= con1 and con2

    return flag1, flag2, flag3, flag4


arr = [ list() for i in xrange(31) ]

for i in xrange(11):
    for j in xrange(i+1):
        for k in xrange(j+1):
            if i-j>2 or j-k>2 or i-k>2:
                continue
            arr[i+j+k].append( (i,j,k) )


T = input()

for case in xrange(T):
    ary = map(int, raw_input().split())
    n, s, p = ary[:3]
    ary = ary[3:]

    dp = [0 for i in xrange(s+1)]
    vis = [0 for i in xrange(s+1)]
    vis[0] = 1

    for num in ary:
        f1, f2, f3, f4 = check(arr[num])

        #print num, f1, f2, f3, f4
        for j in xrange(s, -1, -1):
            va = vis[j]
            if not f2:
                va = 0

            if va:
                a = dp[j] + f3
            else:
                a = 0

            if j != 0 and f1:
                vb = vis[j-1]
            else:
                vb = 0

            if vb:
                b = dp[j-1] + f4
            else:
                b = 0

            vis[j] = va or vb
            dp[j] = max(a, b)

        #print dp
        #print vis

    ans = dp[s]
    print 'Case #%d: %d' % (case+1, ans)

    


