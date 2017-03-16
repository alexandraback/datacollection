T = int(input())


def identifikujZaciatky(B):
    A = N*[True]
    for i in range(0, N):
        A[B[i]] = False
    return A

def behaj(B, i, videne_vsetky):
    dlzka_cyklu = -1
    dlzka_chvosta = -1 #vrcholy mimo cyklu
    ID = N+1
    vstup_do_cyklu = -1
    vrchol = i
    videne = N*[-1]
    k = 0
    while (videne[vrchol] == -1):
        videne[vrchol] = k
        videne_vsetky[vrchol] = True
        k += 1
        vrchol = B[vrchol]
    vstup_do_cyklu = vrchol
    dlzka_chvosta = videne[vstup_do_cyklu]
    dlzka_cyklu = k - dlzka_chvosta
    for j in range(0, N):
        if (videne[j]>=dlzka_chvosta):
            ID = min(ID, j)
    return (dlzka_chvosta, dlzka_cyklu, ID, vstup_do_cyklu)

def spracujKomponent(komponent):
    c = {}
    for dlzka_chvosta, dlzka_cyklu, ID, vstup_do_cyklu in komponent:
        if vstup_do_cyklu not in c:
            c[vstup_do_cyklu] = dlzka_chvosta
        else:
            c[vstup_do_cyklu] = max(c[vstup_do_cyklu], dlzka_chvosta)
    sucet = 0
    for chvost in c.values():
        sucet += chvost
    return sucet + 2


def spracujStvorice(stvorice):
    pole = [[] for x in range(0, N)]
    maximum_cyklus = -1
    for dlzka_chvosta, dlzka_cyklu, ID, vstup_do_cyklu in stvorice:
        maximum_cyklus = max(maximum_cyklus, dlzka_cyklu)
        pole[ID].append((dlzka_chvosta, dlzka_cyklu, ID, vstup_do_cyklu))
    sucet = 0
    for komponent in pole:
        if (len(komponent) > 0):
            if (komponent[0][1] <= 2):
                sucet += spracujKomponent(komponent)
    return max(maximum_cyklus, sucet)


for tid in range(1, T+1):
    N = int(input())
    B = [int(x)-1 for x in input().split(' ')]
    #print(B)
    zaciatky = identifikujZaciatky(B)
    videne_vsetky = N*[False]
    stvorice = []
    for i in range(0, N):
        if (zaciatky[i]):
            stvorice.append(behaj(B, i, videne_vsetky))
    for i in range(0, N):
        if (not videne_vsetky[i]):
            #print('videne vsetky', videne_vsetky)
            stvorice.append(behaj(B, i, videne_vsetky))
    #print(stvorice)
    vysledok = spracujStvorice(stvorice)

    print('Case #{}: {}'.format(tid,str(vysledok)))
