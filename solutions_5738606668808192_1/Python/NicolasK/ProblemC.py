## Test de Miller Rabin
from random import randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31] # etc.

def probably_prime(n, k):
    """Return True if n passes k rounds of the Miller-Rabin primality
    test (and is probably prime). Return False if n is proved to be
    composite.

    """
    if n < 2: return False
    for p in small_primes:
        if n < p * p: return True
        if n % p == 0: return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True
## Fin del test MR

## Creacion de primos
primosBool = [1]*10000
primosBool[0] = 0
primosBool[1] = 0
primos = []
for i in xrange(10000):
    if primosBool[i]:
        primos.append(i)
        k = i+i
        while k < 10000:
            primosBool[k] = 0
            k += i
## Fin creacion de primos

s = open("salida.txt", 'w')
s.write("Case #1:\n")

N = 32
J = 500

def baseNaDecimal(numero, base):
    resultado = 0
    for i in xrange(N):
        resultado += int(numero[i])*(base**(N-i-1))
    return resultado


def binario(n):
    return bin(n)[2::]

encontrados = 0
decCandidato = (2**(N-1))+1
candidato = binario(decCandidato)
while encontrados < J:
    vale = True
    bases = 0
    factores = []
    for base in xrange(2, 11):
        cDecimal = baseNaDecimal(candidato, base)
        if probably_prime(cDecimal, 5):
            vale = False
            break
        else :
            for p in primos:
                if cDecimal % p == 0:
                    bases += 1
                    factores.append(p)
                    break
    if vale and bases == 9:
        encontrados += 1
        strFactores = ""
        for f in factores:
            strFactores += str(f)
            strFactores += " "
        s.write(str(candidato) + " " + strFactores + "\n")
    decCandidato += 2
    candidato = binario(decCandidato)
s.close()


