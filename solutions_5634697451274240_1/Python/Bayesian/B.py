##file_in = "B-test.in"
##file_out = "B-test.out"
##file_in = "B-small-attempt0.in"
##file_out = "B-small-attempt0.out"
file_in = "B-large.in"
file_out = "B-large.out"

def collapse(P):
    if not P:
        return []
    x = P[0]
    Q =[x]
    for k in P:
        if x != k:
            x = k
            Q.append(x)
    return Q

def solve(P):
    Q = collapse(P)
    res = len(Q) - 1
    if not Q[-1]:
        res += 1
    return res
    
with open(file_in, "r") as fin, open(file_out, "w") as fout:
    T = int(fin.readline().strip())
    for case in range(1, T + 1):
        S = fin.readline().strip()
        P = [False if x == '-' else True for x in S]
        print("Case #{0}: {1}".format(case, solve(P)))
        fout.write("Case #{0}: {1}\n".format(case, solve(P)))
