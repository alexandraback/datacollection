import itertools as it

f = open('small.in')
g = open('small.out', 'w')

case = 0
T = int(f.readline()[:-1])

for case in range(T) :
    B, M = [int(i) for i in f.readline()[:-1].split(' ')]
    m = 2**(B-2)
    if M > m : res = 'IMPOSSIBLE'
    else :
        b = list(range(B-2))
        mtx = [[0 for i in range(B)] for i in range(B)]
        res = 'POSSIBLE'
        s = 0
        while True :
            for c in it.combinations(b, s) :
                if s == 0 :
                    mtx[0][-1] = 1
                else :
                    mtx[0][c[0]+1] = 1
                    for idx, arch in enumerate(c[:-1]) :
                        mtx[arch+1][c[idx+1]+1] = 1
                    mtx[c[-1]+1][-1] = 1
                M -= 1
                if M == 0 : break
            if M == 0 : break
            s += 1
        res += '\n' + ''.join([''.join(map(str, l)) + '\n' for l in mtx])[:-1]
    output = 'Case #' + str(case+1) + ': ' + str(res)
    print(output)
    g.write(output + '\n')

f.close()
g.close()
