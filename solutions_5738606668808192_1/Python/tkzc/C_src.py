from math import sqrt
from random import randint

primes = []
searched_jams = []


def cvt2dec(num_list, base):
    global factor_table
    dec = 0
    for x in num_list:
        dec = dec * base + x
    return dec


def prime(max_num):
    global primes
    for k in range(2, int(sqrt(max_num))):
        is_prime = True
        for p in primes:
            if k % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(k)


def check(num_list):
    divisors = []
    for base in range(2, 11):
        dec_num = cvt2dec(num_list, base)
        for p in primes:
            if dec_num % p == 0:
                divisors.append(p)
                break
        if len(divisors) < base - 1:
            return False
    return divisors


def rand_find(n):
    global searched_jams
    while True:
        num_list = [1, ]
        for i in range(1, n-1):
            num_list.append(randint(0, 1))
        num_list.append(1)
        num_str = ''.join(map(str, num_list))
        if num_str in searched_jams:
            continue
        else:
            searched_jams.append(num_str)
        divisors = check(num_list)
        if divisors:
            print(num_str + ' ' + ' '.join(map(str, divisors)))
            break


def main():
    prime(10000)
    input()
    n, j = [int(s) for s in input().split(' ')]
    print('Case #1:')
    for i in range(j):
        rand_find(n)


if __name__ == '__main__':
    main()
