import sys
import math

def solve(ss):
    sums = [(0,[])]
    for i in range(len(ss)):
        s = ss[i]
        sums += [(x[0]+s, x[1]+[s]) for x in sums]
    sums.sort()
    for i in range(1, len(sums)):
        if sums[i-1][0]==sums[i][0]:
            return (sums[i-1][1], sums[i][1])
    return None

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    ss = [int(x) for x in line[1:]]
    res = solve(ss)
    return res

input = sys.stdin

N = int(readline())

for test in range(N):
    ans = do_test(input)
    print 'Case #%d:' % (test+1,)
    if ans is None:
        print 'Impossible'
    else:
        print ' '.join(str(x) for x in ans[0])
        print ' '.join(str(x) for x in ans[1])
    sys.stdout.flush()
    
