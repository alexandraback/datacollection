'''
Created on Apr 9, 2016

@author: Linh
'''

def op(s):
    t = ''
    for p in xrange(len(s)-1, -1, -1):
        t += '+' if s[p] == '-' else '-' 
    return t

with open('b.in') as f:
    lines = f.readlines()

with open('b.out', 'w') as f:    
    T = int(lines[0])
    for i in xrange(1, T+1):
        flips = 0
        l = lines[i].strip()
        s = len(l) * '+'
        if s == l:
            print 'flips', flips
            f.write('Case #%d: %d\n' %(i, flips))
            continue
        
        for j in xrange(len(l)-1, -1, -1):
            if l[j] == '+':
                continue
            if l[0] == '-':
                l = op(l[:j+1])[::-1] + l[j+1:]
                flips += 1
                continue
            
            ind = l.find(op(l[0]))
            l = op(l[:ind]) + l[ind:]
            ind = l.find('-')
            l = op(l[:j+1])[::-1] + l[j+1:]
            flips += 2
            
            if s == l:
                print 'flips', flips
                f.write('Case #%d: %d\n' %(i, flips))
                break
        else:
            print 'flips', flips
            f.write('Case #%d: %d\n' %(i, flips))