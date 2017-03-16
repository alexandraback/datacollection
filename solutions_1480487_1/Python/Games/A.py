################################################################
def solve():
    IN = [int(x) for x in input.readline().split(' ')]
    N,J = (IN[0], IN[1:])
    X = 1.0*sum(J)
    def peak(J):
        J = list(J)
        J.sort()
        X = 1.0*sum(J)
        T = J[0]
        for i in range(len(J)-1):
            n = i+1
            if T+(X/n) < J[i+1]:
                return T+(X/n)
            else:
                X -= n*((J[i+1])-T)
                T = J[i+1]
        return T+(X/len(J))
    T = peak(J)
    return ' '.join([str(max(0, 100*(T-j)/X)) for j in J])
################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start 

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
