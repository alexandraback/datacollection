from math import sqrt

n = 16
j = 50

a = [0] * n
a[0] = 1
a[n - 1] = 1


def bin_to_x(x):
    k = 0
    p = x ** (n - 1)

    for i in a:
        k += i * p
        p /= x
    return k


def divisor(k):
    for i in xrange(2, min(int(sqrt(k)) + 2, 1000)):
        if k % i == 0:
            return i

    return -1


def check():
    divisors = []
    for i in xrange(2, 11):
        div = divisor(bin_to_x(i))
        if div != -1:
            divisors.append(div)
        else:
            return False

    return divisors


def next_num():
    r = n - 2
    while a[r] == 1:
        a[r] = 0
        r -= 1
    a[r] = 1


def to_str():
    s = ""
    for i in a:
        s += str(i)
    return s

cur = 0

f = open("out.txt", "w")

f.write("Case #1:\n")
while cur < j:
    x = check()
    if x:
        f.write(to_str())
        f.write(" ")
        for i in x:
            f.write(str(i))
            f.write(" ")

        f.write("\n")
        cur += 1
    next_num()
