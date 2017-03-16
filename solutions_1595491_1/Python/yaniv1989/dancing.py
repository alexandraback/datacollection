import sys
rl = lambda: sys.stdin.readline().strip()
T = int(rl())
for t in xrange(T):
    line = map(int, rl().split(' '))
    N = line[0]
    S = line[1]
    p = line[2]
    count = 0
    for i in xrange(3, len(line)):
        pts = line[i]
        if pts > 3*p-3:
            count += 1
        elif pts >= 3*p-4 and S > 0:
            if (pts != 0) or (p != 1):
                count += 1
                S -= 1
    print "Case #" + str(t+1) + ": " + str(count)
    
    


