import math


def getdiv(num):
    for i in range(2, int(math.sqrt(num) + 1)):
        if num % i == 0:
            return i
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
for i in range(32769, 65535):
    if cnt == 50:
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
