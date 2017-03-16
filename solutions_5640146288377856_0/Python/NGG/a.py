import sys, os

tn = int(sys.stdin.readline())

for ti in xrange(1, tn+1):
    r, c, w = map(int, sys.stdin.readline().split())
    if w == 1:
        ret = r*c
    else:
        dp = [None]*(c+1)
        dp[w] = w
        for i in xrange(w+1, c+1):
            for j in xrange(i):
                maxj = None
                def do(n):
                    global maxj
                    if maxj is None or n > maxj:
                        maxj = n
                if j >= w and i-1-j >= w:
                    do(min(max(1+dp[i-1-j], 1+dp[j]+((i-1-j)//w)), max(1+dp[j], 1+dp[i-1-j]+(j//w))))
                elif j >= w:
                    do(1+dp[j])
                elif i-1-j >= w:
                    do(1+dp[i-1-j])
                if j == 0 or j == i-1:
                    do(w)
                else:
                    do(w+1)
                #print i, j, maxj
                if j == 0 or maxj < dp[i]:
                    dp[i] = maxj
        #print dp
        ret = (r-1)*(c//w) + dp[c] #(c//w) + (w-1) #dp[c]
    print 'Case #{0}:'.format(ti), ret
