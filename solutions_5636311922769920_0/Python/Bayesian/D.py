import math

##file_in = "D-test.in"
##file_out = "D-test.out"
file_in = "D-small-attempt0.in"
file_out = "D-small-attempt0.out"

def solve(K, C, S):
    N = math.ceil(K/C)
    if N > S:
        return "IMPOSSIBLE"

    resposta = ""
    for i in range(N):
        s = 0
        k = 1
        for q in range(C):
            d = C*i + q
            if d >= K:
                break

            s += d*k
            k *= K
        resposta += str(s+1) + " "
    return resposta

with open(file_in, "r") as fin, open(file_out, "w") as fout:
    T = int(fin.readline().strip())
    for case in range(1, T + 1):
        K, C, S = (int(x) for x in fin.readline().strip().split())
        print("Case #{0}: {1}".format(case, solve(K, C, S)))
        fout.write("Case #{0}: {1}\n".format(case, solve(K, C, S)))
              

    
