from library import *

def median(lst):
    lst.sort()
    l = len(lst)
    if l%2 == 1:
        return lst[l/2]
    return 1.*(lst[l/2-1] + lst[l/2]) / 2

def prof(n):
    two = 0
    thr = 0
    fiv = 0
    sev = 0
    while n % 2 == 0:
        n = n/2
        two += 1
    while n % 3 == 0:
        n = n/3
        thr += 1
    while n % 5 == 0:
        n = n/5
        fiv += 1
    while n % 7 == 0:
        n = n/7
        sev += 1
    assert n == 1
    return [two, thr, fiv, sev]

f = file('c.in1','r')
T = readint(f)
for case in range(1,T+1):
    R,N,M,K = readints(f)
    print 'Case #1:'
    for rcase in range(R):
        arr = [prof(n) for n in readints(f)]
        two = [x[0] for x in arr]
        thr = [x[1] for x in arr]
        fiv = [x[2] for x in arr]
        sev = [x[3] for x in arr]
        d = {}
        d[3] = max(thr)
        d[5] = max(fiv)
        rem = N-d[3]-d[5]
        e = [{} for i in range(4)]
        e[3]['222'] = [0,1,1,1,2,2,2,3]
        e[3]['224'] = [0,1,1,2,2,3,3,4]
        e[3]['244'] = [0,1,2,2,3,3,4,5]
        e[3]['444'] = [0,2,2,2,4,4,4,6]
        e[2]['22'] = [0,1,1,2]
        e[2]['24'] = [0,1,2,3]
        e[2]['44'] = [0,2,2,4]
        e[1]['2'] = [0,1]
        e[1]['4'] = [0,2]
        e[0][''] = [0]
        twostuff = [(sum([e[rem][k].count(t) for t in two]),k) for k in e[rem].keys()]
        #print twostuff
        twoans = max(twostuff)[1]
        print ''.join([str(i)*d[i] for i in d.keys()]) + twoans

