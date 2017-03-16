import sys
import math

def solve(ss):
    X = sum(ss)
    dat = [(ss[i]*1./X, i) for i in range(len(ss))]
    N = len(ss)
    dat.sort()
    tt = [s for s, i in dat]
    s = 0
    sums = [0]
    for t in tt:
        s += t
        sums.append(s)
    res = [0]*N
    for i in range(N):
        minp = 1.
        for k in range(N+1):
            if k==i+1:
                continue
            if k<=i:
                sp = tt[i]*k - sums[k]
                num = k
            else:
                num = k-1
                sp = tt[i]*num - (sums[k] - tt[i])
            p = (1.-sp)/(num+1)
            if p<0:
                p = 0.
            if k==0 or tt[i]+p-tt[k-1]>=-0.00000001:
                minp = min(minp, p)
        res[dat[i][1]] = minp*100
    return res

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    ss = [int(x) for x in line[1:]]
    res = solve(ss)
    return ' '.join(str(x) for x in res)

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()
    
