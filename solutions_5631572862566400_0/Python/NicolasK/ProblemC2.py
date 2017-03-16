# Problema C
import itertools
f = open("C-small-attempt7.in")
s = open("salida.txt", 'w')

casos = int(f.readline())

def esValido(subconjunto, quiereA, loQuieren):
    long = len(subconjunto)
    agarrados = [subconjunto.pop(0)]
    ultimo = agarrados[0]
    while len(agarrados) < long:
        if quiereA[ultimo] not in agarrados:
            if quiereA[ultimo] not in subconjunto:
                return False
            else :
                ultimo = quiereA[ultimo]
                agarrados.append(ultimo)
                subconjunto.remove(ultimo)
        else :
            if quiereA[ultimo] != agarrados[-2]:
                return False
            else :
                f = False
                for i in subconjunto:
                    if quiereA[i] == ultimo and not f:
                        agarrados.append(i)
                        subconjunto.remove(i)
                        ultimo = i
                        f = True
                if not f:
                    return False

    return True

for caso in xrange(1, casos+1):
    s.write("Case #" + str(caso) + ": ")
    cantChicos = int(f.readline())
    BFFS = [int(x) for x in f.readline().split(" ")]
    pares = [(i+1, BFFS[i]) for i in xrange(len(BFFS))]
    print pares
    quiereA = {}
    loQuieren = {}
    for p in pares:
        p0 = p[0]
        p1 = p[1]
        quiereA[p0] = p1
        if p1 not in loQuieren:
            loQuieren[p1] = [p0]
        else :
            loQuieren[p1].append(p0)

    maximaLong = 0
    for cantidad in xrange(1, cantChicos+1):
        i = itertools.combinations(xrange(1, cantChicos+1), cantidad)
        for it in i:
            #print it
            if esValido(list(it), quiereA, loQuieren):
                maximaLong = max(maximaLong, cantidad)
    s.write(str(maximaLong) + "\n")
    print maximaLong

f.close()
s.close()