from sys import *
from math import sqrt


def getnumber(A, base):
    result = 0
    for i in range(len(A))[::-1]:
        result += A[i] * (base ** (len(A) - i - 1))
    return result


def getbinary(integer, length):
    result = []
    while integer >= 2:
        temp = integer
        integer = integer / 2
        result.append(temp - integer * 2)
    result.append(integer)
    if len(result) < length:
        for i in range(length - len(result)):
            result.append(0)
    return result[::-1]


def getstring(A):
    result = ""
    for i in range(len(A)):
        result += str(A[i])
    return result


def solve(T, L, N):
    validnumber = 0
    index = 0
    print "Case #%d:" % (T + 1)
    while validnumber < N:
        data = getbinary(index, L-2)
        if len(data) > L - 2:
            break
        data.append(1)
        data = data[::-1]
        data.append(1)
        data = data[::-1]

        divisor = []
        for base in range(2,11):
            number = getnumber(data, base)
            prime = True
            for i in range(2, int(sqrt(number)) + 1):
                if number % i == 0:
                    divisor.append(i)
                    prime = False
                    break
            if prime:
                divisor.append(-1)

        if (-1 in divisor):
            index += 1
        else:
            print "%s %i %i %i %i %i %i %i %i %i" % (getstring(data), divisor[0], divisor[1], divisor[2], divisor[3], divisor[4], divisor[5], divisor[6], divisor[7], divisor[8])
            index += 1
            validnumber += 1


cases = int(raw_input())

for T in xrange(cases):
    L,N = raw_input().split()
    L = int(L)
    N = int(N)
    solve(T, L, N)
