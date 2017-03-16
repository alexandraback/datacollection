def processData(fileName):
    f = open(fileName)
    
    T = int(f.readline().strip())
    
    for i in xrange(1, T+1):
        N,M = [int(var) for var in f.readline().strip().split(' ')]
        lawn = []
        for j in xrange(N):
            linea = [int(h) for h in f.readline().strip().split(' ')]
            lawn.append(linea)

        #print lawn
        hValues = []
        for h in xrange(N):
            hValues.append(max(lawn[h]))
        vValues = []
        for v in xrange(M):
            vValues.append(max([lawn[j][v] for j in xrange(N)]))
        possible = True
        for iN in xrange(N):
            for iM in xrange(M):
                val = lawn[iN][iM]
                northVal = val if (iN - 1) < 0 else lawn[iN - 1][iM]
                southVal = val if (iN + 1) >= N else lawn[iN + 1][iM]
                eastVal = val if (iM + 1) >= M else lawn[iN][iM + 1]
                westVal = val if (iM - 1) < 0 else lawn[iN][iM - 1]

                possible = possible and ((val >= northVal and val >= southVal and val >= vValues[iM]) or (val >= eastVal and val >= westVal and val >= hValues[iN]))
                if not possible:
                    break
            if not possible:
                break

        print 'Case #' + str(i) + ': ' + ('YES' if possible else 'NO')





processData('B-large.in')
