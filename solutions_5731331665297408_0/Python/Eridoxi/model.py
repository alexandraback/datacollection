import string
import sys
import itertools

def code(perm, zipc):
    s = ""
    for i in perm:
        s = s+zipc[i].rstrip('\n')

    return s

def feasible(perm, N, dest):
    for i in xrange(1,N-1):
        cur = perm[i]
        b = False
        for j in xrange(i):
            pr = perm[j]
            if cur in dest[pr]:
                b = True
                break
        if not b: return False

    return True


def enum(N, M, zipc, dest):
    itr = itertools.permutations(range(0,N))
    best = -1

    for perm in itr:
        if not feasible(perm, N, dest): continue
        c = int(code(perm, zipc))
        if best == -1: best = c
        elif c < best: best = c

    return best

def sv(current, mark, N, M, zipc, dest, back):
    if all(mark[i] == True for i in xrange(N)): return zipc[current]

    return 0


def solve(N, M, zipc, dest):
    val = -1
    for start in xrange(0,N):
        mark = [False for k in xrange(N)]
        sol = sv(start, mark, N, M, zipc, dest, [])
        if val == -1: sol = val
        elif val > int(sol): val = int(sol)

    return val

def main():
    #inp = open('exC', 'r')
    #out = sys.stdout
    inp = open('C-small-attempt0.in', 'r')
    out = open('C-small.out', 'w')
    num_case = int(inp.readline())
    for i in xrange(1, num_case+1) :
        N, M = map(int, inp.readline().split())
        zipc = []
        for j in xrange(0,N):
            zipc.append(inp.readline())
        dest = [[] for p in xrange(N)]
        for j in xrange(0,M):
            k, l = map(int,inp.readline().split())
            dest[k-1].append(l-1)
            dest[l-1].append(k-1)
        #out.write("Case #"+str(i)+": "+str(solve(N, M, zipc, dest))+'\n')
        out.write("Case #"+str(i)+": "+str(enum(N, M, zipc, dest))+'\n')

    inp.close()
    out.close()

if __name__ == "__main__":
    main()
