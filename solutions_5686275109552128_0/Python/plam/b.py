#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def brute(round, PI, min):
    if round+PI[0] < min:
        min = round+PI[0]
    if round >=min:
        return min

    if PI[0] == 1:
        assert min >= round+1
        return round+1
    for i in xrange(1,PI[0]/2+1):
        pid = PI[:]
        top = pid.pop(0)
        pid.append(i)
        pid.append(top-i)
        pid.sort(reverse=True)
#        print round, min, pid
        n = brute(round+1,pid,min)
        if n < min:
            min = n
    return min

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    D = int(data.pop(0))
#    print D
    s = data.pop(0)
#    print s, s.split()
    PI = [int(x) for x in s.split()]
    PI.sort(reverse=True)

#    print brute(0, PI[:],PI[0]), PI
    print brute(0, PI[:],PI[0])

