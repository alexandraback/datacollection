from itertools import product

"?23?"
def acc(C):
    known = 0 # 230
    unknown = [] # [0, 3]
    for e, i in enumerate(reversed(C)):
        if i != '?':
            known += 10**e*int(i)
        else:
            unknown.append(e)

    # [[0, 1, .. 9], [0, 1000, 2000, ... 9000]]
    for p in product(*[[10**i* j for j in range(10)] for i in unknown]):
        yield known + sum(p)

def solve(words):
    C, J = words.split()
    min_diff_C_J = (10**10, 10**10, 10**10)
    for cw in acc(C):
        for jw in acc(J):
            curr = (abs(cw-jw), cw, jw)
            if curr < min_diff_C_J:
                min_diff_C_J = curr
    return ' '.join(str(x).zfill(len(C)) for x in min_diff_C_J[1:])



n_cases = int(input())
for case in range(n_cases):
    print("Case #{}: {}".format(1+case, solve(input())))
