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


def solve(T, J, P, S, K):
    if K >= S:
        print "Case #%d: %d" % (T+1, J * P * S)
        for i in range(1, J + 1):
            for j in range(1, P+1):
                for k in range(1, S+1):
                    print str(i) + ' ' + str(j) + ' ' + str(k)
    else:
        print "Case #%d: %d" % (T+1, J * P * K)
        for i in range(1, J + 1):
            for j in range(1, P+1):
                for k in range(K):
                    result = (i+j+k) % S
                    if result ==0:
                        result = S
                    print str(i) + ' ' + str(j) + ' ' + str(result)
        
cases = int(raw_input())
for T in xrange(cases):
    J, P, S, K = raw_input().split()
    J = int(J)
    P = int(P)
    S = int(S)
    K = int(K)
    solve(T, J, P, S, K)
