from math import ceil

def findPosition(zoznam, K):
    cislo = 0
    for x in zoznam:
        cislo = cislo*K + x
    return cislo+1

T = int(input())
for i in range(1, T+1):
    line = input().split(' ')
    K = int(line[0])
    C = int(line[1])
    S = int(line[2])

    if (S < ceil(K/C)):
        print("Case #"+str(i) + ": IMPOSSIBLE")
    else:
        zoznam_vysledok = []
        for j in range(0, ceil(K/C)):
            zoznam = list(range(j*C, (j+1)*C))
            for x in range(0, len(zoznam)):
                if (zoznam[x] >= K):
                    zoznam[x] = K-1
            zoznam_vysledok.append(findPosition(zoznam, K))
        print("Case #"+str(i) + ":", end = '')
        for x in zoznam_vysledok:
            print(' ' + str(x), end = '')
        print()
