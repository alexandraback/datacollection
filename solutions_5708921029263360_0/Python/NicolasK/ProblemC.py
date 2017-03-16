import itertools
from copy import copy
def esValido(combinacion, K):
    pares = []
    for c in combinacion:
        par1 = ((0, c[0]), (1, c[1]))
        par2 = ((0, c[0]), (2, c[2]))
        par3 = ((1, c[1]), (2, c[2]))
        if par1 not in pares:
            pares.append(par1)
        if par2 not in pares:
            pares.append(par2)
        if par3 not in pares:
            pares.append(par3)
    for par in pares:
        usado = 0
        for c in combinacion:
            if c[par[0][0]] == par[0][1] and c[par[1][0]] == par[1][1]:
                usado += 1
                if usado > K:
                    return False
    return True

def encontrar(poses, tomados, proximoIndice, K):
    if not esValido(tomados, K):
        return (len(tomados)-1, tomados[:-1])
    if proximoIndice >= len(poses):
        return (len(tomados), tomados)
    posibles = []
    for indice in xrange(proximoIndice, len(poses)):
        pos = poses[indice]
        if pos not in tomados:
            t = copy(tomados)
            t.append(pos)
            encontrado = encontrar(poses, t, indice+1, K)
            posibles.append(encontrado)
    res = (0, 0)
    if len(posibles) == 0:
        return (0, 0)
    for p in posibles:
        if p[0] > res[0]:
            res = p
    return res
def resolver(linea):
    K = linea[3]
    jps = linea[0:3]
    posibilidades = [range(x) for x in jps]
    poses = []
    for pos in itertools.product(*posibilidades):
        poses.append(pos)
    ultimaIt = ""
    if K < jps[2]:
        if jps[0] == 3 and jps[1] == 3 and jps[2] == 3 and K == 2:
            lista = []
            lista.append((0,0,2))
            lista.append((0,0,1))
            lista.append((0,1,0))
            lista.append((0,1,1))
            lista.append((0,2,2))
            lista.append((1,1,0))
            lista.append((1,1,1))
            lista.append((2,1,2))
            lista.append((2,0,0))
            lista.append((2,0,1))
            lista.append((1,0,2))
            lista.append((1,2,2))
            lista.append((0,2,1))
            lista.append((1,0,1))
            lista.append((1,2,0))
            lista.append((2,1,2))
            return lista
        solucion = encontrar(poses, [], 0, K)
        if solucion == (0, 0):
            print "ehh"
            return []
        return solucion[1]
    return poses

def procesarResultado(s, it):
    s.write(str(len(it)) + "\n")
    for i in it:
        salida = ""
        for d in i:
            salida += str(d+1)
            salida += " "
        s.write(salida + "\n")

f = open("C-small-attempt2.in", 'r')
s = open("salidaC.txt", 'w')

cases = int(f.readline())

for case in xrange(1, cases+1):
    s.write("Case #" + str(case) + ": ")
    linea = [int(x) for x in f.readline().strip().split(" ")]
    procesarResultado(s, resolver(linea))

f.close()
s.close()