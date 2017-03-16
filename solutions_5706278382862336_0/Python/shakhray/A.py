fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
t = int(fin.readline())


from math import *

def gcd(a, b):
    while (b != 0):
        a, b = b, a % b
    return a


def check_(b):
    while b != 1:
        if b % 2 != 0:
            return 0
        b //= 2
    return 1


for i in range(1, t + 1):
    a, b = fin.readline().split('/')
    a = int(a)
    b = int(b)
    d = gcd(a, b)
    a //= d
    b //= d
    check = check_(b)
    if not check or a > b:
        fout.write("Case #" + str(i) + ": impossible\n")
        continue
    elif a != b:
        k = log2(b / a)
        if k != int(k):
            k = int(k) + 1
        fout.write("Case #" + str(i) + ": " + str(int(k)) + "\n")
    else:
        fout.write("Case #" + str(i) + ": " + "1" + "\n")


fin.close()
fout.close()


