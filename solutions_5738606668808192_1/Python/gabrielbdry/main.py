import math


def getdiv(num):
    if num % 2 == 0:
        return 2
    if num % 3 == 0:
        return 3
    if num % 5 == 0:
        return 5
    if num % 7 == 0:
        return 7
    if num % 11 == 0:
        return 11
    if num % 13 == 0:
        return 13
    if num % 17 == 0:
        return 17
    if num % 19 == 0:
        return 19
    if num % 23 == 0:
        return 23
    if num % 29 == 0:
        return 29
    if num % 31 == 0:
        return 31
    return 0


def getallbaseconv(b):
    out = []
    for j in range(2, 11):
        k = int(b[2:], j)
        divisor = getdiv(k)
        if divisor == 0:
            return out
        else:
            out.append(divisor)
    return out

file = open("txt.out", "w")
file.write("Case #1:\n")
cnt = 0
for i in range(2147483649, 4294967295):
    if cnt == 500:
        break
    if i % 2 != 0:
        b = bin(i)
        divisors = getallbaseconv(b)
        if len(divisors) == 9:
            cnt += 1
            out = b[2:]
            for d in divisors:
                out += ' ' + str(d)
            file.write(out + '\n')
