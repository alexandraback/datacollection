def solve(s, n):
    def isV(c):
        return c in 'aeiou'
    current = 0 # start of seg
    safe = -1 # safe point
    Ccount = 0 # number of longest consecutive cs between current and safe

    total = 0
    l = len(s)
    while current < l:
#        print "current =", current, "ccount = ", Ccount, "safe =", safe
        if Ccount == n:
            total += l - safe # all segs [current, i] (i>safe) counts
        else:
            # try to find enough Cs
            while safe < l-1 and Ccount < n:
                safe += 1
                if isV(s[safe]):
                    # ruined the C run
                    Ccount = 0
                else:
                    Ccount += 1
 #               print "safe = ", safe, "Ccount = ", Ccount
            if Ccount == n:
                total += l - safe
        # advance current
        if not isV(s[current]) and safe-current <=n:
            Ccount -= 1
        current += 1

    return total

import sys
readline = sys.stdin.readline

T = int(readline())
for t in range(T):
    s, n = readline().strip().split()
    n = int(n)
    print "Case #%d: %d" % (t+1, solve(s, n))


                

            
    
