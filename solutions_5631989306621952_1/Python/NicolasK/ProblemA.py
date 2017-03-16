
# Problema A

f = open("A-large.in")
s = open("salida.txt", 'w')

def letraMasGrande(s):
    res = "A"
    for c in s:
        if c > res:
            res = c
    return res


def agregarResto(s, resto):
    pMas = letraMasGrande(resto)
    for i in xrange(len(resto)):
        if resto[i] == pMas:
            s = pMas + s
        else :
            s = s + resto[i]
    return s

def procesar(s):
    if len(s) == 0:
        return s
    if len(s) == 1:
        return s
    pMas = letraMasGrande(s)
    subS = s[0:list(s).index(pMas)]
    resto = s[list(s).index(pMas)::]
    return agregarResto(procesar(subS), resto)

cases = int(f.readline())
for case in xrange(1, cases+1):
    s.write("Case #" + str(case) + ": ")
    initialS = f.readline()
    s.write(procesar(initialS))


f.close()
s.close()