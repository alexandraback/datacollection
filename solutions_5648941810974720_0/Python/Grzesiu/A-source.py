import imp, sys

sys.modules["utils"] = __mod = imp.new_module("utils")
exec """#!/usr/bin/python

from itertools import chain, repeat, izip

def line(*args):
	L = raw_input().strip().split()
	L = izip( L, chain( args, repeat(str) ) )
	return [ type(data) for data, type in L ]	
	
def iline(): return map( int, raw_input().strip().split() )
def fline(): return map( float, raw_input().strip().split() )""" in vars(__mod)

#!/usr/bin/python

from utils import iline, line

D = { 0: 'ZERO', 1:'ONE', 2:"TWO", 3:"THREE", 4:"FOUR", 5:"FIVE", 6:"SIX", 7:"SEVEN", 8:"EIGHT", 9:"NINE" }
Q = {}
for v, word in D.items():
    for c in word:
        if c in Q:
            Q[c].add(v)
        else:
            Q[c] = {v}
        
answer = []

while Q:
    c = min(Q, key=lambda c : len(Q[c]))
    if Q[c]:
        v = min(Q[c])
        answer.append((v,c))
        for e in Q.values():
            e -= {v}
    del Q[c]
    
#print answer, len(answer)

def test():
    word, = line()
    yield
    
    nums = {}
    for c in word:
        nums[c] = nums.get(c,0)+1
        
    ans = []
    for v,c in answer:
        n = nums.get(c,0)
        if n:
            ans += [v]*n
            for c in D[v]:
                nums[c] -= n
                
    ans = map(str, sorted(ans))
    print ''.join(ans)
    
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

