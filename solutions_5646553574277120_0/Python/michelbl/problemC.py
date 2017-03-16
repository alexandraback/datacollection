import os
from collections import Counter, defaultdict

os.chdir('/home/michel/workspace/googlecodejam/')
fi = open('C-small-attempt0.in', 'r')
fo = open('C-small-attempt0.out', 'w')


T = int(fi.readline())

for t in range(T):
    C, D, V = fi.readline().split(' ')
    C = int(C)
    D = int(D)
    V = int(V)
    denoms = fi.readline()[:-1].split(' ')
    denoms = map(int, denoms)
    denoms = sorted(denoms)
    
    Vatt = 0
    idx = 0
    sol = 0
    while Vatt < V:
        if idx < len(denoms) and denoms[idx] <= Vatt + 1:
            Vatt = Vatt + C * denoms[idx]
            idx += 1
        else :
            # create new denomination (of Vatt + 1)
            sol += 1
            Vatt  = Vatt + C * (Vatt + 1)

    fo.write('Case #' + str(t+1) + ': ' + str(sol) + '\n')
    
fi.close()
fo.close()