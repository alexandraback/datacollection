import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        e, r, n = f.readline().split()
        e = int(e)
        r = int(r)
        n = int(n)
        
        dp = []
        for i in xrange(n+1):
            x = [0] * (e+1)
            dp.append(x)
            
        index = 1
        for value in f.readline().split():
            worth = int(value)
            #print "worth", worth
            for spending in xrange(0, e+1):
                for curr_e in xrange(0, e+1):
                    if spending <= curr_e:
                        dp[index][curr_e - spending] = max(dp[index-1][curr_e] + worth * spending, dp[index][curr_e - spending])
                        
            # STUPID
            for i in xrange(r):
                for j in xrange(e, 0, -1):
                    dp[index][j] = dp[index][j-1]
            #print dp
            index += 1
            
        best = max(dp[index-1])
            
        print "Case #%d: %d" % (caseno+1, best)
main()