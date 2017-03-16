#!/usr/bin/env python3
import sys

prime = []
prime_len = 0

def get_prime():
    Max = 1000000
    table = [1] * Max 
    for i in range(4, Max, 2):
        table[i] = 0
    for i in range(3, Max, 2):
        if table[i]:
            for j in range(i**2, Max, 2*i):
                table[j] = 0
    for i in range(2, Max):
        if table[i]:
            prime.append(i)
    global prime_len
    prime_len = len(prime)



def is_prime(x):
    now = 0 
    while True:
        if now >= prime_len:
            return (True, 0)
        if prime[now] ** 2 > x:
            return (True, 0)
        if x % prime[now] == 0:
            return (False, prime[now])
        now += 1

def is_answer(x):
    for i in range(2, 11):
        if is_prime(int(x, i))[0]:
            return False
    return True

def print_answer(x):
    print(x, end=" ")
    for i in range(2, 11):
        print(is_prime(int(x, i))[1], end=" ")
    print()

def get_str(n, x):
    return '1' + str(bin(x))[2:].zfill(n-2) + '1'

def get_input():
    case = int(input())
    tmp = input().split()
    return case, int(tmp[0]), int(tmp[1])

if __name__ == "__main__":
    get_prime()
    case, n, j = get_input()
    now = 0
    print("Case #1:")
    while j:
        s = get_str(n, now)
        if is_answer(s):
            print_answer(s)
            j -= 1
        now += 1
