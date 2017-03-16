size = 1000100
dp = range(size)

def reverse(i):
    reversed = 0
    while i % 10 == 0 and i != 0:
        i/= 10
    while i:
        reversed *= 10
        reversed += i % 10
        i /= 10
    return reversed

for i in xrange(size):
    rn = reverse(i)
    dp[i] = min(i, dp[i-1]+1)
    if rn < size and i % 10 != 0:
        dp[i] = min(dp[i],  dp[reverse(i)]+1)
#for i in xrange(size):
#    print i, dp[i]
#print 'done'

for T in xrange(1, int(raw_input())+1):
    N = long(raw_input())
    print 'Case #%d: %d' % (T, dp[N])
