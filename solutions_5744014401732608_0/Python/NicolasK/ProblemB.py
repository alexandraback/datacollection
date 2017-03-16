from copy import copy
import itertools

def sss(posibilidades, saliendoDesde):
    if saliendoDesde == len(posibilidades):
        return 1
    t = 0    
    for p in posibilidades[saliendoDesde]:
        t += sss(posibilidades, p)
    return t

def agarrar(posibilidades, desde, tomados):
    if desde == len(posibilidades.keys()):
        return tomados
    res = []    
    for i in posibilidades[desde]:
        pos = copy(tomados)
        pos.append(i)
        for r in (agarrar(posibilidades, desde+1, pos)):
            res.append(r)
    return res

def resolver(B, M):
    saltos = [[0]*B]*B
    posibilidades = {}
    for building in xrange(B-1):
        posibilidades[building] = []
        for cant in xrange(B-building):
            for comb in itertools.combinations(xrange(building+1, B), cant):
                posibilidades[building].append(comb)
    print posibilidades.values()
    for i in itertools.product(*posibilidades.values()):
        print i
        if sss(i, 0) == M:
            return ("POSSIBLE", i)
    
    return ("IMPOSSIBLE",0)

f = open("B-small-attempt0.in", 'r')
s = open("salidaB.txt", 'w')

cases = int(f.readline())

for case in xrange(1, cases+1):
    s.write("Case #" + str(case) + ": ")
    linea = f.readline()
    valores = linea.strip().split(" ")
    resultado = resolver(int(valores[0]), int(valores[1]))
    print resultado
    if resultado[0] == "IMPOSSIBLE":
        s.write("IMPOSSIBLE\n")
    else :
        s.write("POSSIBLE\n")
        comb = resultado[1]
        fila = ""
        for i in xrange(int(valores[0])-1):
            fila = ""
            for j in xrange(int(valores[0])):
                if j in comb[i]:
                    fila = fila + "1"
                else :
                    fila = fila + "0"
            s.write(fila + "\n")
        s.write("0"*int(valores[0])+"\n")

print "fin"

f.close()
s.close()