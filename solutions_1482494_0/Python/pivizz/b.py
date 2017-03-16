from collections import defaultdict
import sys

def solve(input):
    N, A, B = input
    A = [(a, i) for i,a in enumerate(A)]
    B = [(b, i) for i,b in enumerate(B)]
    EARNED = defaultdict(int) #[0 for i in xrange(N)]
    A.sort(key=lambda x:x[0], reverse=True)
    B.sort(key=lambda x:x[0], reverse=True)
    res = 0
    lev = 0
    while B:
        bbb = B[-1][0]
        if lev >= bbb:
            i = B.pop()[1]
            lev += 2-EARNED[i]
            res += 1
            EARNED[i] = 2
            continue
        if len(A) == 0:
            return 'Too Bad'
        aaa = A.pop()
        if lev < aaa[0]:
            return 'Too Bad'
        if EARNED[aaa[1]] != 0:
            continue
        res += 1
        lev += 1
        EARNED[aaa[1]] = 1
    return res

def get_next_input(inp):
    N = int(inp.next())
    vals = [map(int, inp.next().strip().split()) for i in xrange(N)]
    A = [v[0] for v in vals]
    B = [v[1] for v in vals]
    return (N, A, B)
    

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

STRANGE = []
NG = []
for i in xrange(T):
    N, A, B = ARGS[i]
    res = RES[i]
    if min(B) > N and res != 'Too Bad':
        STRANGE.append((N,A,B,i,res))
    elif min(B) == N and res != 'Too Bad' and res != 2*N:
        STRANGE.append((N,A,B,i,res))

for i in xrange(T):
    g.write('Case #' + str(i+1) + ': ' + str(RES[i]) + '\n')
g.close()