'''
Created on May 12, 2013

@author: rycus
'''

import re

def solve(name, n):
    pattern = '.*[^aeiou]{' + str(n) + ',}.*'
    
    res = 0
    sub = name
    while re.match(pattern, sub):
        res += 1
        sub = sub[0:-1]
    
    if res > 0:
        return res + solve(name[1:], n)
    else:
        return 0

if __name__ == '__main__':
    with open('../a.in', 'r') as infile:
        with open('../a.out', 'w') as outfile:
            T = int(infile.readline())
            for t in xrange(T):
                name, n = infile.readline().split()
                ret = solve(name, int(n))
                print 'Case #' + str(t+1) + ':', ret
                outfile.write('Case #' + str(t+1) + ': ' + str(ret) + '\n')
    