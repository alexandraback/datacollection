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
        f.write('Case #%s: %s\n' %(i, ' '.join([str(j) for j in xrange(1,S+1)])))