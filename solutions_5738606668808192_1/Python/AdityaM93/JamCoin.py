import math


def get_factor(n):
    lim = math.sqrt(n)
    i = 2
    while i < lim:
        if n % i == 0:
            return i
        i += 1
    return -1


def get_num(rep, base):
    i = sol = 0
    for x in rep:
        sol += x * math.pow(base, i)
        i += 1
    return sol

i = 0
n = 32
j = 500
coin = [0] * n
coin[0] = coin[n - 1] = 1
counter = 0
while counter < j:
    i = 1
    while coin[i] != 0:
        coin[i] = 0
        i += 1
    coin[i] = 1
    factors = []
    for b in range(2, 11):
        f = get_factor(get_num(coin, b))
        factors.append(f)
        if f == -1:
            break
    if factors[len(factors) - 1] == -1:
        continue
    counter += 1
    string = ""
    for x in coin:
        string += str(x)
    string = string[::-1]
    for x in factors:
        string += " " + str(x)
    print(string)
