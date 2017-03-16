import sys, time

rl = lambda: sys.stdin.readline().strip()
T = int(rl())
for t in xrange(T):
    A, B = map(int, rl().split(' '))
    count = 0
    for i in xrange(A, B+1):
        s = str(i)
        d = {}
        for j in xrange(1, len(s)):
            newn = int(s[j:] + s[0:j])
            if (i < newn) and (newn <= B):                
                if not(d.has_key(newn)):
                    count += 1
                    d[newn] = True
    print "Case #" + str(t+1) + ": " + str(count)

