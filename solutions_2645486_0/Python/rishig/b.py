from library import *
from itertools import *

# given pairs return the key corresponding to the greatest value
def argmax(pairs):
    return max(pairs, key= lambda x: x[1])[0]
# given values return the index of the greatest value
def argmax_index(values):
    return argmax(enumerate(values))

def recstep(start, end, E, R, V):
    assert end >= R
    l = len(V)
    assert end-start <= l*R
    if end-start == l*R:
        return 0
    ind = argmax_index(V)
    endl = min(E, start+R*ind)
    startr = max(0, end-R*(l-ind))
    return (endl-startr)*V[ind] + recstep(start, endl, E, R, V[:ind]) + recstep(min(startr+R,E), end, E, R, V[ind+1:])

f = file('b.in1','r')
T = readint(f)
for case in range(1,T+1):
    E,R,N = readints(f)
    V = readints(f)
    ans = recstep(E, R, E, R, V)
    print 'Case #%d: %d' % (case, ans)
