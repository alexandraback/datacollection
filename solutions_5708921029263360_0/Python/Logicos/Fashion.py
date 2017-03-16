i = int(input())
for case in range(i):
    ret = []
    inp = str(input())
    inp = inp.split(" ")
    J = int(inp[0])
    P = int(inp[1])
    S = int(inp[2])
    K = int(inp[3])

    for j in range(J):
        laatste = 0
        js = []
        for _ in range(S):
            js.append(0)
        for p in range(P):
            s = laatste
            jp = 0
            ps = []
            for a in range(S):
                ps.append(0)
            for l in range(S):
                if js[s] < K and ps[s] < K and jp < K :
                    js[s] += 1
                    ps[s] += 1
                    jp += 1
                    ret.append("{} {} {}".format(j + 1, p + 1, s + 1))
                    laatste = s + 1
                    if laatste >= S:
                        laatste = 0
                s += 1
                if(s >= S):
                    s = 0

    print("Case #{}: {}".format(case + 1, len(ret)))
    for i in range(len(ret)):
        print(ret[i])

# 4
# 1 1 1 10
# 1 2 3 2
# 1 1 3 2
# 1 2 3 1

# 1
# 3 3 3 2