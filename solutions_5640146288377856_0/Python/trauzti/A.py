from math import ceil
T = int(raw_input())

"""
[][m][s][s] 3

[s][s][s][s][s][s][s]

[m][m][m][m][s]
[m][m][m][m][m]
"""

for tc in xrange(1,1+T):
    R, C, W = map(int, raw_input().split())
    #x = solve(R,C,W)

    ans = R * ceil(C/float(W)) + (W-1)
    #print ans
    print "Case #%d: %d" % (tc, ans)

