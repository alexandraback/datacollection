fin = open('A-large.in', 'r')
fout = open('A-large.out', 'w')

cases = int(fin.readline()[:-1])

for case in range(cases) :
    N = map(int, fin.readline()[:-1].split(' '))
    N = N[1:]
    X = sum(N)
    passed = []
    badSumValue = 0
    while True :
        res = []
        size = len(N)
        flag = False
        for index, n in enumerate(N) :
            temp = 100*(float(2*X - badSumValue)/(size*X) - float(n)/X)
            if temp < 0 :
                passed.append(index)
                badSumValue += n
                flag = True
                break
            res.append(round(temp,6))
        if flag :
            N.pop(index)
        else :
            break
    indexSum = 0
    for index in passed :
        res.insert(index + indexSum, 0.0)
        indexSum += 1
    res = str(res).replace('[','').replace(']','').replace(',','')
    print 'Case #' + str(case+1) + ': ' + str(res)
    fout.write('Case #' + str(case+1) + ': ' + str(res) + '\n')
    
fin.close()
fout.close()
