import sys


def solve(shyMax, l):
    #shyMax = S_Max
    #l = the string given
    N = 0
    sumShy = int(l[0])

    for i in xrange(1,len(l)):
        #sumShy += int(l[i])
        if sumShy < i:
            #print i
            N += (i - sumShy)
            sumShy += 1
        sumShy += int(l[i])

    return N

T = int(sys.stdin.readline())
for case in xrange(T):
    q = sys.stdin.readline().strip().split(' ')
    #print q
    ans = solve(int(q[0]), q[1])
    print 'Case #%d: %d' % (case + 1, ans)
    

