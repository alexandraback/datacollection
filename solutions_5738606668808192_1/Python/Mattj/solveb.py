from __future__ import print_function
from array import *
import math
import sys
import random
import string

debug = True
test = False

primes = list([2])
def is_prime(x):
    for i in primes:
        if x%i==0:
            return False
    return True

def divisor(x):
    for i in primes:
        if x%i==0:
            return i
    return None

def gen_primes(x):
    for i in range(3,x,2):
        if is_prime(i):
            primes.append(i)
            # print('prime:'+str(i),flush=True)

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
        # print("checking prime:"+str(n), flush=True)
        if is_prime(n):
            return False
    return True

def found(x,N):
    s = "1"+int2bin(x).zfill(N-2)+"1"
    print(s,end=" ", flush=True)
    for base in range(2,11):
        n = int(s,base)
        print(str(divisor(n)),end=" ")
    print("", flush=True)


gen_primes(100000)
# print('finished',flush=True)
T = get_first()
N,J = get_next()

seen = list()

print("Case #" + str(1) + ": ")
x = 0
for j in range(1,J+1):
    # if debug: print('trying:'+str(x), flush=True)
    while check(x,N)==False:
        # if debug: print('trying:'+str(x), flush=True)
        x+=1
    seen.append(x)
    found(x,N)
    x+=1
