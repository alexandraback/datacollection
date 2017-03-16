T = int(input())

def doplnNuly(s, k):
    return (k-len(s))*'0' + s

def getKey(item):
    return item[0]

def rob(s, A):
    #print('s', s)
    riadky = []
    stlpce = []
    for i in range(0, 2*N-1):
        if (s[i] == '1'):
            riadky.append(A[i])
        else:
            stlpce.append(A[i])
    riadky = sorted(riadky, key = getKey)
    #print('riadky', riadky)
    zvacsujuce = True
    for i in range(0, N-1):
        for j in range(0, N-1):
            zvacsujuce = zvacsujuce and (riadky[i][j] < riadky[i+1][j]) and (riadky[i][j] < riadky[i][j+1])
    if (not zvacsujuce):
        return None
    videne_stlpce = N*[False]
    for j in range(0, N-1): #index stlpca
        ok_stlpec = False
        for i in range(0, N): # tip
            ok_riadok = True
            for k in range(0, N): #ocheckovat vsetky riadky
                ok_riadok = ok_riadok and (riadky[k][i] == stlpce[j][k])
            if (ok_riadok):
                videne_stlpce[i] = True
                ok_stlpec = True
                break

        if (not ok_stlpec):
            return None
    chybajuci_stlpec = -1
    for i in range(0, N):
        if (not videne_stlpce[i]):
            chybajuci_stlpec = i
            break
    odpoved = []
    for i in range(0, N):
        odpoved.append(riadky[i][chybajuci_stlpec])
    return odpoved

for tid in range(1, T+1):
    N = int(input())
    A = []
    for i in range(0, 2*N-1):
        riadok = [int(x) for x in input().split(' ')]
        A.append(riadok)
    #rint(A)
    for i in range(0, pow(2, 2*N-1)):
        s = bin(i)
        s = s.lstrip('-0b')
        s = doplnNuly(s, 2*N-1)
        jednotky = s.count('1')
        odpoved = [-1]
        if (jednotky == N):
            odpoved = rob(s, A)
            if (odpoved):
                break
    print('Case #{}: {}'.format(tid,' '.join(str(x) for x in odpoved)))
