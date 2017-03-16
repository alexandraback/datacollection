
def f(e,n):
    if dp[e][n]!=-1:
        return dp[e][n]

    result = 0
    if n == N:
        # end of list
        dp[e][n] = result
        return result

    for i in xrange(0,e+1):

        new_e = e-i+R
        if new_e>E:
            new_e = E
        temp = f(new_e,n+1)+i*val[n]

        if temp>result:
            result = temp

    dp[e][n] = result
    return result

# main
T = int(raw_input())
N = 0
E = 0
R = 0
val = []
dp = []

for testcase in xrange(0,T):
    E, R, N = raw_input().split(" ")
    E, R, N = int(E), int(R), int(N)
    val = [ int(v) for v in raw_input().split(" ")]
    dp = []
    for i in xrange(0,E+1):
        dp += [[-1 for asd in xrange(0,N+1)]]
    print "Case #%d:" % (testcase+1), f(E,0)
