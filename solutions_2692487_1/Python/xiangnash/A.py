import sys


T = int(sys.stdin.readline())
for ca in xrange(1, T+1):
    [A, N] = [int(v) for v in sys.stdin.readline().split(" ")]
    mote = [int(v) for v in sys.stdin.readline().split(" ")]
    
    mote.sort()
    #print mote
    
    ans = N
    cur = 0
    for ix in range(N):
        if mote[ix] < A:
            A += mote[ix]
        else:
            tmp = cur + N-ix
            if tmp < ans:
                ans = tmp
            while A <= mote[ix] and cur < ans:
                A += A-1
                cur += 1
            A += mote[ix]
        if cur >= ans:
            break
    if cur < ans:
        ans = cur
    
    print "Case #%d: %d" % (ca, ans) 

