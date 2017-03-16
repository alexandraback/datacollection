from sys import argv
from random import choice
from math import sqrt, floor

def prime(liczba):
    for i in range(2, min(floor(sqrt(liczba)), 100000)):
        if liczba % i == 0:
            return i
    return True

[n,k] = list(map(int,argv[1:]))

res = []
while len(res) < k:
    liczba = "1"
    for i in range(n-2):
        liczba += choice(["0","1"])
    liczba += "1"
    w = []
    for i in range(2, 11):
        x = int(liczba, i)
        w.append(prime(x))
    if True not in w:
        res.append((liczba, w))
print("Case #1:")
for liczba, swiatkowie in res:
    print(liczba, " ".join(map(str, swiatkowie)))
