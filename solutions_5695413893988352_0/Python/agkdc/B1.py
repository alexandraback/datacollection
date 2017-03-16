import os
import math

inf = open('input.in','r')
inp = inf.read().split('\n')
inf.close()
T = int(inp.pop(0))

def close_match(c, j):
    if len(filter(lambda x:x=='?',c))==0 and len(filter(lambda x:x=='?',j))==0:
        return (c, j, abs(int(''.join(c))-int(''.join(j))))
    else:
        possible = []
        for i in range(len(c)):
            if c[i] == '?':
                for k in range(10):
                    c1 = c[:]
                    c1[i] = str(k)
                    possible += [close_match(c1, j)]
                possible = filter(lambda x:x[2] == min([y[2] for y in possible]), possible)
                possible = filter(lambda x:''.join(x[0]) == min([''.join(y[0]) for y in possible]), possible)
                possible = filter(lambda x:''.join(x[1]) == min([''.join(y[1]) for y in possible]), possible)
                return possible[0]
            elif j[i] == '?':
                for k in range(10):
                    j1 = j[:]
                    j1[i] = str(k)
                    possible += [close_match(c, j1)]
                possible = filter(lambda x:x[2] == min([y[2] for y in possible]), possible)
                possible = filter(lambda x:''.join(x[0]) == min([''.join(y[0]) for y in possible]), possible)
                possible = filter(lambda x:''.join(x[1]) == min([''.join(y[1]) for y in possible]), possible)
                return possible[0]

outf = open('output','w')
for i in range(T):
    print i
    C, J = [list(x) for x in inp.pop(0).split(' ')]
    p = close_match(C, J)
    outf.write('Case #%d: %s %s\n'%(i+1, ''.join(p[0]), ''.join(p[1])))



outf.close()