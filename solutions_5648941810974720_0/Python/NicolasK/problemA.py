##Problem A

f = open("A-small-attempt0.in")
s = open("salida.txt", 'w')


numeros = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
numerosS = ["Z", "ONE", "W", "H", "FOUR", "V", "X", "S", "G", "I"]

def contar(s):
    letras = {}
    for l in s:
        if l not in letras:
            letras[l] = 1
        else :
            letras[l] += 1
    return letras


def resolver(s):
    letras = contar(s)
    zeros = letras.get("Z",0)
    dos = letras.get("W",0)
    seis = letras.get("X", 0)
    ocho = letras.get("G", 0)
    for i in xrange(zeros):
        for l in numeros[0]:
            letras[l] -= 1
    for i in xrange(dos):
        for l in numeros[2]:
            letras[l] -= 1
    for i in xrange(seis):
        for l in numeros[6]:
            letras[l] -= 1
    for i in xrange(ocho):
        for l in numeros[8]:
            letras[l] -= 1
    sietes = letras.get("S", 0)
    for i in xrange(sietes):
        for l in numeros[7]:
            letras[l] -= 1
    cincos = letras.get("V", 0)
    for i in xrange(cincos):
        for l in numeros[5]:
            letras[l] -= 1
    tres = letras.get("H", 0)
    for i in xrange(tres):
        for l in numeros[3]:
            letras[l] -= 1
    nueves = letras.get("I", 0)
    for i in xrange(nueves):
        for l in numeros[9]:
            letras[l] -= 1
    cuatros = letras.get("U", 0)
    for i in xrange(cuatros):
        for l in numeros[4]:
            letras[l] -= 1
    unos = letras.get("O", 0)

    return "0"*zeros+"1"*unos+"2"*dos+"3"*tres+"4"*cuatros+"5"*cincos+"6"*seis+"7"*sietes+"8"*ocho+"9"*nueves

cases = int(f.readline())

for case in xrange(1, cases+1):
    s.write("Case #" + str(case) + ": ")
    s.write(resolver(f.readline()))
    s.write("\n")


f.close()
s.close()