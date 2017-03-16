from re import *
from sys import stderr
import functools
def readint():
    return int(input())
def readfloat():
    return float(input())
def readarray(N, foo=input):
    return [foo() for i in range(N)]
def readlinearray(foo=int):
    return map(foo, input().split())

def NOD(a, b):
    while b:
        a,b = b, a%b
    return a

def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(max+1) if primes[x]]

def is_prime(N):
    i = 3
    if not(N % 2):
        return 0
    while i*i < N:
        if not(N % i):
            return 0
        i += 3
    return 1


table = {'11': ('1', False), '1i': ('i', False), '1j': ('j', False), '1k': ('k', False), 'i1': ('i', False), 'ii': ('1', True), 'ij': ('k', False), 'ik': ('j', True), 'j1': ('j', False), 'ji': ('k', True), 'jj': ('1', True), 'jk': ('i', False), 'k1': ('k', False), 'ki': ('j', False), 'kj': ('i', True), 'kk': ('1', True)}

class Q(object):
    def __init__(self, c = '1', neg=False):
        self.c = c
        self.neg = neg

    def __mul__(self, other):
        a = table[self.c + other.c]
        return Q(a[0], self.neg ^ other.neg ^ a[1])


def p(x, n):
    if n == 0:
        return Q()
    y = p(x, n // 2)
    y = y * y
    if n % 2:
        return y * x
    return y

case_number = readint()
for case in range(case_number):
    a, b = readlinearray()
    s = [Q(c) for c in input()]
    begin = s * min(b, 10)
    end = p(functools.reduce(Q.__mul__, s), b - min(b, 10))
    bq = Q()
    oki = None
    okj = None
    for i in range(len(begin)):
        bq *= begin[i]
        if bq.c != 'i' or bq.neg:
            continue
        oki = i
        break
    bq = Q()
    if oki is not None:
        for j in range(i + 1, len(begin)):
            bq *= begin[j]
            if bq.c != 'j' or bq.neg:
                continue
            okj = j
            break
        if okj is not None:
            e = functools.reduce(Q.__mul__, begin[j + 1:]) * end
            if e.c == 'k' and not e.neg:
                print("Case #%s: %s" % (case + 1, 'YES'))
                continue


    #qq = functools.reduce(Q.__mul__, (Q(c) for c in input()))
    #qq = p(qq, b)
    #print(qq.c, qq.neg)
    print("Case #%s: %s" % (case + 1, 'NO'))
    #if qq.c == '1' and qq.neg:
        #print("Case #%s: %s" % (case + 1, 'YES'))
    #else:
        #print("Case #%s: %s" % (case + 1, 'NO'))
