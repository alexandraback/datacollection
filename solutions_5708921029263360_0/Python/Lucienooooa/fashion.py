import itertools

num_case = int(input())
for case_t in range(1, num_case+1):
    Input = [int(i) for i in input().split(" ")]
    J, P, S, K = Input

    JP = {}
    PS = {}
    JS = {}
    RES = []
    for s in range(S-1, -1, -1):
        for p in range(P-1, -1, -1):
            for j in range(J-1, -1, -1):
                jp = 10*j + p
                ps = 10*p + s
                js = 10*j + s

                if jp in JP:
                    JP[jp] += 1
                    if JP[jp] > K:
                        continue
                        JP[jp] -= 1
                else: JP[jp] = 1

                if ps in PS:
                    PS[ps] += 1
                    if PS[ps] > K:
                        continue
                        PS[ps] -= 1
                else: PS[ps] = 1

                if js in JS:
                    JS[js] += 1
                    if JS[js] > K:
                        continue
                        JS[js] -= 1
                else: PS[ps] = 1

                RES.append((j, p, s))

    print("Case #%d: %d"%(case_t, len(RES)))
    ANS = "\n".join(["%d %d %d"%(combin[0]+1, combin[1]+1, combin[2]+1) for combin in RES])
    print(ANS)



