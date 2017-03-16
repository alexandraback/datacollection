import sys

T = int(sys.stdin.readline())

for t in xrange(1, T+1):
    N = int(sys.stdin.readline())
    
    if N==0:
        print 'Case #'+str(t)+': INSOMNIA'
    else:
        digits = [False for _ in xrange(10)]
        cur = 0
        while not all(digits):
            cur+=N
            for c in str(cur):
                digits[ord(c)-ord('0')] = True
        
        print 'Case #'+str(t)+': '+str(cur)

        