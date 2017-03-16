# Problema B

f = open("B-small-attempt1.in")
s = open("salida.txt", 'w')

def encontrarMasBajo(listas, indice):
    if len(listas) == 0:
        return []
    res = listas[0][indice]
    indices = []
    for l in xrange(len(listas)):
        lista = listas[l]
        i = lista[indice]
        if i < res:
            res = i
            indices = [l]
        elif i == res:
            indices.append(l)
    return indices
cases = int(f.readline())
for case in xrange(1,cases+1):
    s.write("Case #" + str(case) + ": ")
    N = int(f.readline())
    listas = []
    for i in xrange(2*N-1):
        listas.append([int(x) for x in f.readline().split(" ")])
    print "Case ", str(case)
    print "N = ", N
    print listas
    pares = []
    indice = 0
    indiceFinal = 0
    hermano = ""
    for indice in xrange(len(listas)):
        bajos = encontrarMasBajo(listas, indice)
        if len(bajos) == 0:
            break
        if len(bajos) == 1:
            indiceFinal = indice
            hermano = listas[bajos[0]]
            pares.append((listas.pop(bajos[0]), 0))

        else:
            pares.append((listas.pop(bajos[1]), listas.pop(bajos[0])))

    print "pares: "
    print pares

    for ip in xrange(len(pares)):
        p = pares[ip]
        if p[1] == 0:
            s.write(str(p[0][ip]) + " ")
            continue
        pos = []
        for i in xrange(2):
            numero = p[i][indiceFinal]
            pos.append(numero)
        if pos[0] == pos[1]:
            s.write(str(pos[0]) + " ")
        else :
            if pos[0] != hermano[pares.index(p)]:
                s.write(str(pos[0]) + " ")
            else :
                s.write(str(pos[1]) + " ")
    s.write("\n")


f.close()
s.close()