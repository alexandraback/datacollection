import sys, string
import time

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

def expand(seq, orig_seq):
    new = ""
    for ch in seq:
        if ch == "G":
            new += "G" * len(orig_seq)
        else:
            new += orig_seq
    return new

T = readint()

# try a few numbers to figure out how the sequence behaves
def experiment(K,C,S):
    C += 2
    print
    
    # consider only the worst cases: only one tile is golden
    for i in range(K):
        orig_seq = "L" * K
        orig_seq = orig_seq[:i] + "G" + orig_seq[i+1:]
        seq = orig_seq
        for j in range(C-1):
            seq = expand(seq, orig_seq)
        print seq
    
    s0 = seq
    # level 1: original seq
    # level 2: G on i == j/K, and on i == j%K
    # level 3: G on i == j/K/K, on i == (j/K)%K, and j%K
    # and so on
    print C,K
    for i in range(K):
        seq = ""
        for j in range(K**C):
            if C==2 and (i == j/K or i == j%K):
                seq += "G"
            elif C==3 and (i == j/K/K or i == (j/K)%K or i == j%K):
                seq += "G"
            elif C==4 and (i == j/K/K/K or i == (j/K/K)%K or i == (j/K)%K or i == j%K):
                seq += "G"
            else:
                seq += "L"
        print seq
    s1 = seq
    print s1 == s0

# pick j (which tile to clean) so that it covers
# the cases where tile i is golden, for each i in i_list
# we need to satisfy the div/mod conditions from the above experiment
def pick(K,C,S,i_list):
    
    j = 0
    p = 1
    for i in i_list:
        j += i * p
        p *= K
    
    max = K**C
    return j+1 if j < max else None

for t in range(T):
    K,C,S = readlist()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    print >> sys.stderr, K, C, S
    last = 0
    out = []
    while last < K:
        # with one tile, we can cover at most C "worst cases"
        # (worst case "i" is where only tile "i" is golden)
        next = min(last+C, K)
        worst_cases = range(last, next)
        sol = pick(K,C,S, worst_cases)
        print >> sys.stderr, worst_cases, sol, "<=", K**C
        out.append(str(sol))
        last = next
    
    if len(out) <= S:
        print " ".join(out)
    else:
        print "IMPOSSIBLE"
