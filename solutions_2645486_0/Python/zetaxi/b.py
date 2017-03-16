# 2013A1 B

from copy import deepcopy

T=int(input())

for a in range(T):

    ERN=input()
    ERN=ERN.split(' ')
    E=int(ERN[0])
    R=int(ERN[1])
    N=int(ERN[2])

    E0 = E

    gain = 0

    v=input()
    v=v.split(' ')
    v=[int(x) for x in v]
    
    w = deepcopy(v)
    w.sort()
    w.reverse()

    for i in range(N):
        if (v[i]==w[0]):
            s=E
            E=E-s
            gain = gain + s*v[i]
            w.pop(0)

        r=max(E+R-E0,0)
        r=min(E,r)
        E=E-r
        gain = gain + r*v[i]

        E=E+R
        if (E>E0):
            E=E0
    E=E-R
    gain = gain + E*v[N-1]
    print('Case #'+str(a+1)+': '+str(gain))
