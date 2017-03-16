##Problem C
import itertools

f = open("C-small-attempt1.in")
s = open("salida.txt", 'w')

cases = int(f.readline())

for case in xrange(1, cases+1):
    pares = int(f.readline())
    combs = []
    for par in xrange(pares):
        combs.append(tuple(f.readline().strip().split(" ")))
    usadasComoPrimera = []
    usadasComoSegunda = []
    for par in combs:
        if par[0] not in usadasComoPrimera:
            usadasComoPrimera.append(par[0])
        if par[1] not in usadasComoSegunda:
            usadasComoSegunda.append(par[1])
    salir = False
    for l in xrange(1, pares+1):
        for c in itertools.combinations(combs, l):
            usadasComoPrimerax = []
            usadasComoSegundax = []
            for par in c:
                if par[0] not in usadasComoPrimerax:
                    usadasComoPrimerax.append(par[0])
                if par[1] not in usadasComoSegundax:
                    usadasComoSegundax.append(par[1])
            if len(usadasComoPrimera) == len(usadasComoPrimerax) and len(usadasComoSegunda) == len(usadasComoSegundax):
                salir = True
        if salir:
            break

    s.write("Case #" + str(case) + ": " + str(pares-l) + "\n")

f.close()
s.close()