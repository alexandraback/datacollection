from copy import deepcopy

def get_cases(filename):
    with open(filename, 'r') as f:
        T = int(f.readline())
        cases = []
        for t in range(T):
            cases.append([int(x) for x in f.readline().split()])
        return T, cases

def compute_ways(a, B):
    s = [0 for i in range(B)]
    s[0] = 1
    for j in range(1, B):
        for i in range(0,j):
            s[j] += a[i][j] * s[i]
    return s[B-1]

def get_slides(B, M):
    if M > 2**(B-2):
        return ('IMPOSSIBLE', [])
    a = [[0 for j in range(B)] for i in range(B)]
    for i in range(B-1):
        a[i][i+1]=1
    i = 0
    while (i<min(B-2,M-1)):
        a[i][B-1] = 1
        i += 1
    ways = i+1
    if ways == M:
        return ('POSSIBLE', a)
    best = (2**(B-2), deepcopy(a))
    for j in range(2, B-1):
        for i in range(0, j-1):
            # compute ways if we add a[i][j] = 1
            a[i][j] = 1
            ways = compute_ways(a, B)
            if ways > M:
                if ways <= best[0]:
                    best = (ways, deepcopy(a))
                a[i][j] = 0
            elif ways == M:
                return ('POSSIBLE', a)
    return get_slides_strat1(best[1], B, M)

def get_slides_strat1(a, B, M):
    print('strat1')
    best = (0, deepcopy(a))
    for j in range(B-1, 1, -1):
        for k in range(0, B-j):
            # compute ways if we add a[i][j] = 1
            a[k][j+k] = 0
            ways = compute_ways(a, B)
            if ways < M:
                if ways >= best[0]:
                    best = (ways, deepcopy(a))
                a[k][j+k] = 1
            elif ways == M:
                return ('POSSIBLE', a)
    return get_slides_strat2(best[1], B, M)

def get_slides_strat2(a, B, M):
    print('strat2') 
    best = (2**(B-2), deepcopy(a))
    for j in range(2, B):
        for i in range(0, j-1):
            # compute ways if we add a[i][j] = 1
            a[i][j] = 1
            ways = compute_ways(a, B)
            if ways > M:
                if ways <= best[0]:
                    best = (ways, deepcopy(a))
                a[i][j] = 0
            elif ways == M:
                return ('POSSIBLE', a)
    return get_slides_strat1(best[1], B, M)

def b_print(res, T, filename):
    with open(filename, 'w') as f:
        for t in range(T):
            f.write("Case #{0}: {1}\n".format(t+1, str(res[t][0])))
            for row in res[t][1]:
                f.write(' '.join([str(x) for x in row]) + '\n')

if __name__ == '__main__':
    filename = 'B-small-attempt1.in'
    T, cases = get_cases(filename)
    res = [get_slides(case[0], case[1]) for case in cases]
    b_print(res, T, 'B-small1.out')