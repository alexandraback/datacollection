#!/usr/bin/env python
import sys
#import numpy as np
 

   
if __name__ == '__main__':
    first = True
    idx = 1
    dp = [0 for _ in range(1000001) ]
    dp[1] = 1
    for i in range(2, 1000001):
        dp[i] = 1 + dp[i-1]
        rev = int(str(i)[::-1])
        if rev < i and i % 10 != 0:
        	dp[i] = min(dp[i], 1 + dp[rev])
        
    #print dp[1:100]
    for line in sys.stdin:
        if first: 
            first = False
            T = int(line.strip())
        elif T > 0:
            N = int(line)
            T -= 1
            print "Case #%d: %d"%(idx, dp[N])
            idx += 1

        else:
        	break
    