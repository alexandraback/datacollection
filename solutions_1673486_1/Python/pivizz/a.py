import sys

def solve(input):
    A,B,P = input
    prob = 1.0
    res = B+2
    for C in xrange(A):
        prob *= P[C]
        res = min(res, B-A+1+2*(A-1-C)+(B+1)*(1-prob))
    return res

def get_next_input(inp):
    s = inp.next().strip().split()
    A = int(s[0])
    B = int(s[1])
    P = map(float, inp.next().strip().split())
    return (A,B,P)

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