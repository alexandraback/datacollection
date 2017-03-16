fin = open("/home/ahmed/Desktop/C-large.in", "r")
fout = open("/home/ahmed/Desktop/C-large.out", "w")

import random
def isPrime(x):
    if (x <= 1):
        return False
    y = 2
    while (y * y <= x and y <= 1000):
        if (x % y == 0):
            return False
        y += 1 + y % 2
    return True
def ok(s):
    for x in range(2, 11):
        if (isPrime(int(s, x))):
            return False
    return True

T = int(fin.readline())
idd = 1
while (T > 0):
    T -= 1
    n, j = map(int, fin.readline().split())
    L = {}
    msk = 0
    fout.write("Case #" + str(idd) + ":\n")
    idd += 1
    while (len(L) != j):
        s = bin(random.randint(0, (1 << (n - 2)) - 1))[2:]
        while (len(s) < n - 2):
            s = "0" + s
        s = "1" + s + "1"
        if (ok(s)):
            L[s] = True
    for item in L:
        fout.write(item)
        for b in range(2, 11):
            x = int(item, b)
            y = 2
            while (True):
                if (x % y == 0):
                    fout.write(" " + str(y))
                    break
                y += 1 + y % 2
        fout.write("\n")
        
fout.close()
