import sys
sys.stdin = open("B-small-attempt0.in", "r")
sys.stdout = open("out.txt", "w")
T=input()
for cas in xrange(1, T+1):
    s = raw_input()
    n = len(s)
    dp0 = [0]*(n+1)
    dp1 = [0]*(n+1)
    if s[0] == "+":
        dp0[0], dp1[0] = 0,1
    else:
        dp0[0], dp1[0] = 1,0
    for i in xrange(1, n):
        if s[i] == "+":
            dp0[i] = min(dp0[i-1], dp1[i-1]+1)
            dp1[i] = min(dp0[i-1]+1, dp1[i-1]+2)
        else: #s[i] == "-"
            dp0[i] = min(dp0[i-1]+2, dp1[i-1]+1)
            dp1[i] = min(dp0[i-1]+1, dp1[i-1])
    print "Case #%d: %d" %(cas, dp0[n-1])
