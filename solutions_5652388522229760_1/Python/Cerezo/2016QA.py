#wrong, somehow

import heapq
import random

def Next(N):
    digits = set()
    if N == 0:
        return 'INSOMNIA'
    iN = 0
    while len(digits) < 10:
        iN += N
        digits = digits.union(set(list(str(iN))))
    return iN
    #return 'SUSPICIOUS'
        

input = open(r'A-large.in')

T = int(input.readline())

sol = []

for i in xrange(T):
    N= int(input.readline().strip())
    sol += [Next(N)]
    if not i%10: print i


tofile = True
if tofile:
    with open(r'./outputA-L.txt', 'w') as output:
        for i in range(len(sol)):
            output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
    print sol



'''
def Next_slow(L,N,M,D,W):
    W.sort()
    avail = W[:] #when would the next load finish
    ft = []
    for load in xrange(L):
        j = avail.index(min(avail)) #use heap here
        ft.append(avail[j]) #automatically sorted
        avail[j] += W[j]
    #print ft
    
    dryer = [D for i in range(M)]
    for i in xrange(M):
        ft[i] += D
    for i in xrange(M, len(ft)):
        k = dryer.index(min(dryer)) #heap again
        nextdr = max(ft[i], dryer[k])
        ft[i] = nextdr + D
        dryer[k] = nextdr + D
    #print ft
    
    return ft[-1]
'''
