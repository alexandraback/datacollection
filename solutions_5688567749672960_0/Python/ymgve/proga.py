import sys

import psyco; psyco.full()

# def recursive(memo, n):
    # if n == 1:
        # return 1
        
    # if n in memo:
        # return memo[n]
    
    # res = recursive(memo, n-1) + 1
    # if n % 10 != 0:
        # t = int(str(n)[::-1])
        # if t < n:
            # res = min(res, recursive(memo, t) + 1)
        
    # memo[n] = res
    # return res
    
def main():
    optimal = [999999999999] * 1000001
    optimal[1] = 1
    for i in xrange(2, 1000001):
        if i % 10 != 0:
            optimal[i] = min(optimal[i-1], optimal[int(str(i)[::-1])]) + 1
        else:
            optimal[i] = optimal[i-1] + 1
            
    #print optimal[1:30]
    
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        target = int(f.readline())
        
        print "Case #%d: %d" % (caseno+1, optimal[target])
        
        
            
        
main()