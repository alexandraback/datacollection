import math

inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

def Serve(P,time):
    if len(P) == 0:
        return time
    if int(max(P)/2) > 1:
        P_nonsplit = filter(lambda y:y>0,[x-1 for x in P])
        P_split = P[:]
        maxP = P_split.pop(P_split.index(max(P)))
        P_split += [int(maxP/2),maxP-int(maxP/2)]
        return min(Serve(P_nonsplit,time+1),Serve(P_split,time+1))
    else:
        P_nonsplit = filter(lambda y:y>0,[x-1 for x in P])
        return Serve(P_nonsplit,time+1)


T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    D = int(inp.pop(0))
    P = map(lambda x:int(x),inp.pop(0).split(' '))
    outf.write('Case #%d: %d\n'%(i+1, Serve(P,0)))
outf.close()