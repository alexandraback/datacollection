from itertools import *

f = open('C-large.out', 'w')

N = 32
J = 500
numWritten = 0
evenIndices = range(2, N, 2)
oddIndices = range(1, N, 2)

f.write("Case #1:\n")

for numOnes in xrange(0, N/2-1):
    for oddSet in combinations(oddIndices, numOnes):
        for evenSet in combinations(evenIndices, numOnes):
            s = [0] * N
            s[0] = 1
            s[N-1] = 1
            for i in oddSet:
                s[i] = 1
            for j in evenSet:
                s[j] = 1
            f.write(''.join(str(el) for el in s) + ' 3 2 5 2 7 2 3 2 11\n')
            numWritten += 1
            if numWritten >= J:
                break
        if numWritten >= J:
            break
    if numWritten >= J:
        break

f.close()
