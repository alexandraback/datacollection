inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    Smax, shy = inp.pop(0).split(' ')
    Smax = int(Smax)
    Fmin = 0
    clapping = 0
    shy = [int(x) for x in shy]
    for s in range(Smax):
        clapping = Fmin + sum(shy[:s+1])
        if clapping < s+1 and shy[s+1] > 0:
            Fmin += s+1 - clapping
    outf.write('Case #%d: %d\n'%(i+1,Fmin))
outf.close()