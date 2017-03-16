from __future__ import print_function
from array import *
import math
import random
import string

debug = False
test = False
def isprime(n):
    '''check if integer n is a prime'''

    # make sure n is a positive integer
    n = abs(int(n))

    # 0 and 1 are not primes
    if n < 2:
        return False

    # 2 is the only even prime number
    if n == 2:
        return True

    # all other even numbers are not primes
    if not n & 1:
        return False

    # range starts with 3 and only needs to go up
    # the square root of n for all odd numbers
    for x in range(3, int(n**0.5) + 1, 2):
        if n % x == 0:
            return False

    return True
def int2bin(i):
    if i == 0: return "0"
    s = ''
    while i:
        if (i & 1) == 1:
            s = "1" + s
        else:
            s = "0" + s
        i = int(i/2)
    return s

def get_first():
    if test==False:
        return int(input())
def get_next(t=1):
    if test==False:
        x=input().split(" ")
        return [int(x[0]),int(x[1])]


def check(x,N):
    s = "1"+int2bin(x).zfill(N-2)+"1"
    for base in range(2,11):
        n = int(s,base)
        if isprime(n)==True:
            return False
    return True

def divisor(n):
    for i in range(2,n-1):
        if n%i==0:
            return i

def found(x,N):
    s = "1"+int2bin(x).zfill(N-2)+"1"
    print(s,end=" ")
    for base in range(2,11):
        n = int(s,base)
        print(str(divisor(n)),end=" ")
    print("")


T = get_first()
N,J = get_next()

print("Case #" + str(1) + ": ")
x = 0
for j in range(1,J+1):
    while check(x,N)==False:
        if debug: print(str(x))
        x += 1
    found(x,N)
    x+=1
