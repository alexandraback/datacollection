from random import randint
from math import log, floor
import sys

def to_reversed_binary(n):
    r = []
    while n > 0:
        r.append(n & 1)
        n /= 2
    return r


def test(a, n):
    b = to_reversed_binary(n - 1)
    k = 1
    for i in range(len(b) - 1, -1, -1):
        x = k
        k = (k * k) % n
        if k == 1 and x != 1 and x != n - 1:
            return True
        if b[i] == 1:
            k = (k * a) % n
    if k != 1:
        return True
    return False


def is_it_prime(n):
    if n == 1:
        return False
    s = int(floor(log(n, 2)))
    for j in range(1, s + 1):
        a = randint(1, n - 1)
        if test(a, n):
            return False    
    return True

def convert (n, base):
    result = 0
    new_base = 1
    while n > 0:
        result = result + new_base * (n % 2)
        n = n / 2
        new_base = new_base * base
    return result

def divisor (n):
    for i in range(2, 10000):
        if n % i == 0:
            return i
    return -1

answer = []

f = open('output-large.txt', 'w')

def check (n):
    if n % 2 == 0:
        return False
    if n in answer:
        return False
    for base in range(2, 11):
        value = convert(n, base)
        if is_it_prime(value) == True or divisor(value) == -1:
            return False
    return True

def generate (len):
    stop = False
    n = -1
    count = 0
    while stop == False and count < 100:
        n = randint(2 ** (len - 1), (2 ** len) - 1)
        count = count + 1
        if check(n) == True:
            stop = True
            answer.append(n)
    if count < 100:
        temp = n
        digits = []
        while temp > 0:
            digits.append(temp % 2)
            temp = temp / 2
        for i in range(len):
            f.write(str(digits[len - i - 1]))

        f.write(' ')
        for base in range(2, 11):
            f.write(str(divisor(convert(n, base))))
            f.write(' ')

N = 32
J = 500
f.write('Case #1:\n')
for i in range(J):
    generate(N)
    if i != J - 1:
        f.write('\n')
    
f.close()