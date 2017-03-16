import sys
from math import sqrt
from random import randint
def sustava(s, k):
    vysledok = 0
    for i in range(0, len(s)):
        vysledok = vysledok * k + int(s[i])
    return vysledok

def najdiDelitela(c):
    for i in range(2, min(int(sqrt(c)+1), 10000)):
        if (c%i == 0):
            return i
    return -1

def skontroluj(s):
    zoznam = []
    for i in range(2, 11):
        c = sustava(s, i)
        #print('c', c, 'i', i)
        delitel = najdiDelitela(c)
        if (delitel == -1):
            return None
        else:
            zoznam.append(delitel)
    return zoznam

def generuj(N):
    nah_cislo = '1'
    for i in range(1, N-1):
        nah_cislo +=str(randint(0, 1))
    return nah_cislo + '1'


T = int(input())
line = input().split(' ')
N = int(line[0])
J = int(line[1])
d = {}
while (len(d) < J):
    #print(len(d))
    cislo = generuj(N)
    delitele = skontroluj(cislo)
    if (delitele):
        d[cislo] = delitele


print("Case #1:")
for key, value in d.items():
    print(key, end = '')
    for x in value:
        print(' ' + str(x), end = '')
    print()
