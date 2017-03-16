# -*- coding: utf-8 -*-

optable = [['1', 'i', 'j', 'k'],
           ['i','-1', 'k','-j'],
           ['j','-k','-1', 'i'],
           ['k', 'j','-i','-1']]

opdict = {}
for x in optable[0]:
    for y in optable[0]:
        opdict[(x, y)] = optable[optable[0].index(x)][optable[0].index(y)]

def op(x, y):
    r = opdict[(x[1], y[1])]
    if r[0] == '-':
        return (- x[0] * y[0], r[1])
    else:
        return (x[0] * y[0], r[0])  

Tc = input()

for Tn in xrange(1, Tc + 1):
    L, X = map(int, raw_input().strip().split())
    if X > 4:
        X = X % 4 + 4
    s = raw_input().strip() * X

    cur = (1, '1')
    foundi = foundk = False
     
    for c in s:
        cur = op(cur, (1, c))
        if not foundi and cur == (1, 'i'):
            foundi = True
        elif foundi and cur == (1, 'k'):
            foundk = True

    print 'Case #%d:' % Tn,
    if foundi and foundk and cur == (-1, '1'):
        print 'YES'
    else:
        print 'NO'
        
        
    
    