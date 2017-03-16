'''
Created on Apr 9, 2016

@author: Linh
'''
with open('d.in') as f:
    lines = f.readlines()

with open('d.out', 'w') as f:    
    T = int(lines[0])
    for i in xrange(1, T+1):
        K, C, S = [int(j) for j in lines[i].split()]
        if K > S * C:
            f.write('Case #%s: IMPOSSIBLE\n' %i)
            continue
        res = []
        for k in xrange(0, K, C):
            j = k
            for c in xrange(1, C):
                t = j*K + j + 1
                if t >= K**C:
                    break
                j = t
            res.append(j+1)
        f.write('Case #%s: %s\n' %(i, ' '.join([str(j) for j in res])))