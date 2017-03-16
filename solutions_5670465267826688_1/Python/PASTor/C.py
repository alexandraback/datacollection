#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f

def pprintm():   
    keys = sorted(m.keys())
    print >>sys.stderr, '\t', '\t'.join(keys)
    
    for k in keys:
        print >>sys.stderr, k, '\t',
        for v in keys:
            print >>sys.stderr, m[k][v], '\t',
        print >>sys.stderr, ''

dest = ['i', 'j', 'k']

m = {
    '1': {  '1': '1',   'i': 'i',   'j': 'j',   'k': 'k'  },
    'i': {  '1': 'i',   'i': '-1',  'j': 'k',   'k': '-j'  },
    'j': {  '1': 'j',   'i': '-k',  'j': '-1',  'k': 'i'  },
    'k': {  '1': 'k',   'i': 'j',   'j': '-i',  'k': '-1'  }
}

for x in ['1','i','j','k']:
    m['-'+x] = {}
    for y in ['1','i','j','k']:
        if m[x][y][0] == '-':
            sign=''
            val = m[x][y][1]
        else: 
            sign='-'
            val = m[x][y][0]        
        m['-'+x][y] = sign + val
        m[x]['-'+y] = sign + val
        m['-'+x]['-'+y] = m[x][y]

# print >>sys.stderr, pprintm()




T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    L, X = map(int, raw_input().split() )
    s = raw_input()
        
    cache_iterations = {}
    
    res = "NO"

    x = 0
    symb = '1'
    l = 0
    
    while x<X:
        if (symb, dest[l]) in cache_iterations:
            if l!=2:
                break
            else: 
                #Jump to the end
                delta = x - cache_iterations [(symb, dest[l])]
                x = X - ((X - x) % delta)
                cache_iterations = {}
                continue
            
        cache_iterations [(symb, dest[l])] = x
        for i in s:
            symb = m[symb][i]
            if l!=2 and symb == dest[l]:
                l+=1
                symb = '1'
                
        x += 1
    
    #Final letter
    if l==2 and symb == dest[2]:
        res = 'YES'
    
    print res
            
    
