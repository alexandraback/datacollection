import random

fin = open('C-small.in', 'r')
fout = open('C-small.out', 'w')

cases = int(fin.readline()[:-1])

for case in range(cases) :
    N = map(int, fin.readline()[:-1].split(' '))
    N = N[1:]
    res = {}
    win = []
    while True :
        sample = random.sample(N, random.randint(1,20))
        sample.sort()
        sampleSum = sum(sample)
        if sampleSum in res :
            if res[sampleSum] != sample :
                win = [sample, res[sampleSum]]
                break
        else :
            res[sampleSum] = sample
    res = '\n' + str(win[0]).replace('[','').replace(']','').replace(',','') + '\n' + str(win[1]).replace('[','').replace(']','').replace(',','')
    print 'Case #' + str(case+1) + ':' + str(res)
    fout.write('Case #' + str(case+1) + ':' + str(res) + '\n')
    
fin.close()
fout.close()
