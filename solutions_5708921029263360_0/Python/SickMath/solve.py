import itertools as it

f = open('small.in')
g = open('small.out', 'w')

case = 0
T = int(f.readline()[:-1])

for case in range(T) :
    J, P, S, K = [int(i) for i in f.readline()[:-1].split(' ')]
    res = '\n'
    ban3  = set()
    ban12 = {}
    ban13 = {}
    ban23 = {}
    J = list(range(J))
    P = list(range(P))
    S = list(range(S))
    for k in range(K) :
        for j, p, s in it.product(*(J, P, S)) :
            if (j, p, s) not in ban3 :
                if ban12.get((j, p), 0) < K :
                    if ban13.get((j, s), 0) < K :
                        if ban23.get((p, s), 0) < K :
                            res += str(j+1) + ' ' + str(p+1) + ' ' + str(s+1) + '\n'
                            ban3.add((j, p, s))
                            ban12[j, p] = ban12.get((j, p), 0) + 1
                            ban13[j, s] = ban13.get((j, s), 0) + 1
                            ban23[p, s] = ban23.get((p, s), 0) + 1
    res = res[:-1]
    res = str(res.count('\n')) + res
    output = 'Case #' + str(case+1) + ': ' + str(res)
    print(output)
    g.write(output + '\n')

f.close()
g.close()
