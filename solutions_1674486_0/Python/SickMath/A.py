letter = 'A'
size = 'small'

fin = open(letter + '-' + size + '.in', 'r')
fout = open(letter + '-' + size + '.out', 'w')

cases = int(fin.readline()[:-1])

for case in range(cases) :
    N = int(fin.readline()[:-1])
    P = []
    for n in range(N) :
        Mi = map(int, fin.readline()[:-1].split(' '))
        Mi = [i-1 for i in Mi]
        if len(Mi) > 1 :
            for m in Mi[1:] :
                P.append([n, m])
    P1 = P[:]
    size = 2
    while True :
        act = len(P)
        for p in P1 :
            a, b = p
            paths = filter(lambda x : len(x) == size and x[size-1] == a, P)
            for path in paths :
                P.append(path + [b])
        size += 1
        if len(P) == act :
            break
    SS = [(i[0], i[len(i)-1]) for i in P]
    if len(set(SS)) == len(SS) :
        res = 'No'
    else :
        res = 'Yes'
    print 'Case #' + str(case+1) + ': ' + str(res)
    fout.write('Case #' + str(case+1) + ': ' + str(res) + '\n')
    
fin.close()
fout.close()
