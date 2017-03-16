from math import sqrt
from scipy.misc import comb #use comb(n,k,True)

def findi(fix, d, steps, indices):
    if d == len(steps):
        indices.append(fix)
    else:
        for j in range(steps[d-1], steps[d]):
            findi(fix+[j], d+1, steps, indices)

def Next(N, words):
    words.sort()
    steps = [0]
    for i in range(1, len(words)):
        if words[i][0] != words[i-1][0]:
            steps.append(i)
    #print steps
    steps.append(N)
    indices = []
    findi([], 1, steps, indices)
    #print indices
    firsts = set([w[0] for w in words])
    seconds = set([w[1] for w in words])
    m = N
    for i in indices:
        x = set([words[j][1] for j in i])
        if len(seconds - x) < m:
            m = len(seconds -x)
    #m = minimal size of seconds - sceonds used in index
    return str(N - len(firsts)- m)

#input = open(r'sample.in')
input = open(r'C-small-attempt0.in')
#input = open(r'C-large.in')

T = int(input.readline())
sol = []

for i in xrange(T): #xrange(T):
    N = (int(input.readline().strip()))
    words = []
    for j in range(N):
        words.append(input.readline().strip().split())
    sol += [Next(N, words)]
    if not i% 10:
        print 'Case ', i+1, ' done.'

tofile = True
if tofile:
    with open(r'./outputC.txt', 'w') as output:
        for i in range(T):
            output.write('Case #%s: %s \n' % (i+1, sol[i]))
                        
else:
    print sol
