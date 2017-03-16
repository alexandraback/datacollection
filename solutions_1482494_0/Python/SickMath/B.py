fin = open('B-small.in', 'r')
fout = open('B-small.out', 'w')

cases = int(fin.readline()[:-1])

for case in range(cases) :
    N = int(fin.readline()[:-1])
    AB = []
    for n in range(N) :
        ab = map(int, fin.readline()[:-1].split(' '))
        AB.append(ab)
    S = 0
    res = 0
    while len(AB) > 0 :
        oneshot = filter(lambda x : x[1] <= S and x[0] != -1, AB)
        if len(oneshot) > 0 :
            AB.pop(AB.index(oneshot[0]))
            S += 2
            res += 1
            continue
        canbeatsec = filter(lambda x : x[1] <= S and x[0] == -1, AB)
        if len(canbeatsec) > 0 :
            AB.pop(AB.index(canbeatsec[0]))
            S += 1
            res += 1
            continue
        canbeatfir = filter(lambda x : -1 < x[0] <= S, AB)
        if len(canbeatfir) > 0 :
            canbeatfir = sorted(canbeatfir, key = lambda x : - x[1])
            canbeatfir[0][0] = -1
            S += 1
            res += 1
            continue
        res = 'Too Bad'
        break
    print 'Case #' + str(case+1) + ': ' + str(res)
    fout.write('Case #' + str(case+1) + ': ' + str(res) + '\n')
    
fin.close()
fout.close()
