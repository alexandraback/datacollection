'''
Created on Apr 9, 2016

@author: Linh
'''

with open('a.in') as f:
    lines = f.readlines()

with open('a.out', 'w') as f:    
    T = int(lines[0])
    for i in xrange(1, T+1):
        seen = set()
        N = int(lines[i])
        for j in xrange(1, 100000):
            seen.update(set([k for k in str(j*N)]))
            if len(seen) >= 10:
                f.write('Case #%d: %d\n' %(i, j*N))
                break
        else:
            f.write('Case #%d: INSOMNIA\n' %i)