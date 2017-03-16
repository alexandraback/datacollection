import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    x = sys.stdin.readline()
    [maxshy, shys] = x.split()

    nPersons = 0
    nInvite  = 0
    for shylevel, nshys in enumerate(shys):
        nshys = int(nshys)
        if nshys == 0:
            continue
        if nPersons >= shylevel:
            nPersons += nshys
        else:
            nInvite  += (shylevel - nPersons)
            nPersons += nInvite + nshys
    print('Case #{}: {}'.format(icase,nInvite))
