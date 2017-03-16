#!/usr/bin/python

# use this file like this:
# ./c.py < ../../Downloads/c.in > c.out

l2s = lambda x: ''.join(x)
s2l = lambda x: list(x)

def debug(*arg):
    if DEBUG:
        for x in arg:
            print x,
            print ":",
        print

DEBUG = False

def solver(inp):
    """
    inp is a list of the input parameters. This solver returns a list of the
    output parameters
    """
    J,P,S,K = inp
    outs = []
    pairs = {}
    p = range(P)
    j = range(J)
    s = range(S)

    for _s in s:
        for _p in p:
            for _j in j:
                pairs.setdefault(('S', _p, _j), set())
                pairs.setdefault(('J', _s, _p), set())
                pairs.setdefault(('P', _s, _j), set())

    for _j in j:
        for _p in p:
            for _s in s:               
             
        
                if len(pairs[('S', _p, _j)]) < K and  len(pairs[('J', _s, _p)]) < K and len(pairs[('P', _s, _j)]) < K:
                    outs.append((_j+1, _p+1, _s+1))
                    pairs.setdefault(('S', _p, _j), set()).add((_p, _j, _s))
                    pairs.setdefault(('J', _s, _p), set()).add((_p, _j, _s))
                    pairs.setdefault(('P', _s, _j), set()).add((_p, _j, _s))   
    
    
    
    return outs

    
cases = int(raw_input())
for case in range(1, cases+1):
    inp = [int(i) for i in raw_input().split(' ')]
    outs = solver(inp)
    print 'Case #{}: {}'.format(case, len(outs))
    for out in outs:

           print ' '.join([str(x) for x in out])
                                            
 

