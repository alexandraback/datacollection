import random
import math
import numpy as np

def pow_mod_p(n, x, p):
    res = 1
    while x > 0:
        if x & 1:
            res *= n
            res %= p
            x -= 1
        else:
            n *= n
            n %= p
            x >>= 1
    return res

def strassen_test(n):
    d = n - 1
    s = 0
    ds = []
    while d & 1 == 0:
        s += 1
        d >>= 1
        ds.append(d)
    ds = ds[:-1]

    tests_num = 10

    for i in range(0, tests_num):
        a = random.randint(1, n - 1)
        x = pow_mod_p(a, d, n)
        prime = False
        if x != 1 and x != n - 1:
            for r in ds:
                x = pow_mod_p(a, r, n)
                if x == n - 1:
                    prime = True
        else:
            continue
        if not prime:
            return False

    return True



def generate_random_jamcoin(length, seen_jamcoins):
    repeat = True
    while repeat:
        l = tuple([random.choice([0, 1]) for i in range(length-2)])
        repeat = l in seen_jamcoins
    seen_jamcoins.add(l)
    return l

def get_d_powers(max_length):
    d = tuple([[1]*(max_length + 1) for i in range(11)])
    for i in range(2, 11):
        for j in range(1, max_length + 1):
            d[i][j] = d[i][j-1] * i
    return d

def get_numbers_for_jc(jc, d_powers):
    length = len(jc)
    out = []
    for d in range(2, 11):
        num = 1 + d_powers[d][length + 1]
        for i, digit in enumerate(jc):
            if digit == 1:
                num += d_powers[d][length - i]
        assert (num )
        out.append(num)
    return out

def test_all_not_prime(nums):
    for n in nums:
        if strassen_test(n):
            return False
    return True 

def get_factors(nums):
    res = []
    for i in nums:
        limit = min(math.ceil(math.sqrt(i)) + 1, 10000)
        for d in range(2, limit):
            if i % d == 0:
                res.append(d)
                break
    return res

def tests():
    assert(strassen_test(37441))
    assert(strassen_test(59))
    assert(strassen_test(3881))
    assert(strassen_test(19559))
    assert(strassen_test(1361))
    for x in rwh_primes1(100000):
        assert(strassen_test(x))

def main():
    random.seed()
    T = int(input())
    for t in range(T):
        n, j = (int(x) for x in input().split(" "))
        seen_jamcoins = set()
        good_jamcoins = 0
        d_powers = get_d_powers(n - 1)
        print("Case #{}:".format(t + 1))
        while good_jamcoins < j:
            jc = generate_random_jamcoin(n, seen_jamcoins)
            nums = get_numbers_for_jc(jc, d_powers)
            if not test_all_not_prime(nums):
                continue
            f = get_factors(nums)
            if len(f) < 9:
                continue

            print("1", end="")
            for d in jc:
                print(d, end="")
            print("1 ", end="")
            for d in f:
                print("{} ".format(d), end="")
            print("")
            good_jamcoins += 1


if __name__ == "__main__":
    #tests()
    main()