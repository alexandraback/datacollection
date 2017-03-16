import sys
t= input()

for i in range(int(t)):
    line = sys.stdin.readline().split()
    r,t = int(line[0]),int(line[1])

    #binary search for that value
    lo = 1
    hi = 1000000000000000000000000000000000000

    while lo < hi:
        mid = lo + (hi-lo)/2
        #print 2*mid*r + 2*mid*mid -mid , mid
        if 2*mid*r + 2*mid*mid -mid > t:
            hi = mid
        else:
            lo = mid+1
    print "Case #%d: %d"%(i+1,lo-1)
