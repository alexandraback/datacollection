from optparse import OptionParser

def memoize(f):
    cache= {}
    def memf(A, B):
        id = tuple(A) + tuple(B)
        if id not in cache:
            cache[id] = f(A, B)
        return cache[id]
    return memf

@memoize
def solve_c(A, B):
    #print "solve_c"
    if len(A) == 0 or len(B) == 0:
        return 0
    An, At = A[0]
    Bn, Bt = B[0]
    if At == Bt:
        nprod = min(An, Bn)
        An -= nprod
        Bn -= nprod
        remainA = []
        remainB = []
        if An != 0:
            remainA.append((An, At))
        if Bn != 0:
            remainB.append((Bn, Bt))
        remainA += A[1:]
        remainB += B[1:]
        return nprod + solve_c(remainA, remainB)
    n1 = solve_c(A[1:], B)
    n2 = solve_c(A, B[1:])
    return max(n1, n2)
    
def problem_C(filename):
    with open(filename, 'rU') as fin:
        lines = [l.rstrip("\n") for l in fin.readlines()]
    ntestcases = int(lines[0])
    pos = 1
    for i in range(ntestcases):
        N, M =  [int(s) for s in lines[i*3+1].split(" ")]
        Ai = [int(s) for s in lines[i*3+2].split(" ")]
        Bi = [int(s) for s in lines[i*3+3].split(" ")]
        A = [(Ai[j*2], Ai[j*2+1]) for j in range(len(Ai)/2)]
        B = [(Bi[j*2], Bi[j*2+1]) for j in range(len(Bi)/2)]
        #print "Case", i+1, ":", N, M, A, B
        
        print "Case #%d: %s" % (i+1, solve_c(A, B))





if __name__ == "__main__":
    parser = OptionParser()
    (options, args) = parser.parse_args()

    if len(args) != 1:
        parser.error("incorrect number of arguments")
    problem_C(args[0])
