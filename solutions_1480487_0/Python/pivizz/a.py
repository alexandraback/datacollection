import sys
from collections import defaultdict

def solve(input):
    N, S = input
    X = sum(S)
    invX = 1.0/X
    S = sorted([(s,i) for i,s in enumerate(S)])
    i = 2
    sY = S[1][0] - S[0][0]
    while i < N:
        sYn = sY + (S[i][0] - S[i-1][0]) * i
        if sYn > X:
            break
        sY = sYn
        i += 1
    results = defaultdict(int)
    bb = S[i-1][0]
    addition = (1.0 - sY * invX) / i
    for j in xrange(i):
        rrr = (bb - S[j][0]) * invX + addition
        results[S[j][1]] = rrr
    Results = [results[j]*100.0 for j in xrange(N)]
    return ' '.join(map(str, Results))

def get_next_input(inp):
    s = inp.next().strip().split()
    N = int(s[0])
    S = map(int, s[1:])
    return (N, S)


f = open('in.txt', 'r')
g = open('out.txt', 'w')
T = int(f.next().strip())
ARGS = []

for i in xrange(T):
    ARGS.append(get_next_input(f))

if len(sys.argv) > 1:
    import multiprocessing
    pool = multiprocessing.Pool(int(sys.argv[1]))
    mapper = lambda func, iter: pool.map(func, iter, 1)
else:
    mapper = map

RES = mapper(solve, ARGS)

for i in xrange(T):
    g.write('Case #' + str(i+1) + ': ' + str(RES[i]) + '\n')
g.close()