
import fileinput

import itertools as it


lines = fileinput.input()
nb_cases = int(lines.next())


def print_result(n, res):
    print 'Case #%d: %s'%(n, res)

def deceitful(N,K,T):
    N=sorted(N)
    K=sorted(K)
    scoreN = 0
    for i in range(T):
        maxK = K[-1]
        maxN = N[-1]
        minK = K[0]
        minN = N[0]

        if maxK>maxN:
            N_told = maxK-(maxK-maxN)/2
            N_chosen = N.pop(0)
        else:
            N_told = maxN-(maxN-maxK)/(i+1)
            N_opt = min(filter(lambda x : x>minK, N)) 
            N_chosen = N.pop(N.index(N_opt))

        K_chosen = Kstrat(K, N_told)
        if N_chosen > K_chosen: scoreN +=1
    return scoreN

def Kstrat(K,N_chosen):
    Kopt = filter(lambda x:x>N_chosen,K)
    return K.pop(K.index(min(Kopt) if Kopt else min(K)))

def playwar(N,K,T):
    """
    Wild guess :
    K's optimal would be to always use the lighest
    block that is heavier to N's, or at all if no option
    N plays first, she should play lightest
    """
    N=list(N)
    K=list(K)
    scoreN = 0
    for i in range(T):
        N_chosen = N.pop(N.index(min(N)))
        K_chosen = Kstrat(K, N_chosen)
        if N_chosen > K_chosen: scoreN +=1
    return scoreN

B = 2.0

for i in range(1, nb_cases+1):
    T = int(lines.next())
    N = map(float, lines.next().strip().split())
    K = map(float, lines.next().strip().split())
    print_result(i,'%d %d'%(deceitful(N,K,T),playwar(N,K,T)))

