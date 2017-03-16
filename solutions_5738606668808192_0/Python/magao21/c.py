import sys
from random import randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997] # etc.
def find_factor(n):
    i = 2;
    while i * i <= n:
        if n % i == 0:
            return i;
        i += 1;
def probably_prime(n, k):
    """Return True if n passes k rounds of the Miller-Rabin primality
    test (and is probably prime). Return False if n is proved to be
    composite.

    """
    if n < 2: return False
    for p in small_primes:
        if n < p * p: return True
        if n % p == 0: return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True
N = 16;
J = 50;
print "Case #1: ";
for num in range(pow(2, N - 1) + 1, pow(2, N)):
    if (num % 2 == 0):
        continue;
    factors=[1,1,1,1,1,1,1,1,1];
    s = bin(num);
    TMP = s.split('b');
    s = TMP[1];
    flag = True;
    for base in range(2, 11):
        tmp = 0;
        k = 1;
        for bit in s[::-1]:
            tmp += k * int(bit);
            k *= base;
        if (probably_prime(tmp, 100)):
            flag = False;
            break;
        else:
            factors[base-2] = find_factor(tmp);
    if not flag:
        continue;
    else:
        J-=1;
        print s,
        for i in range(8):
            print factors[i],
        print factors[8]
        if J == 0:
            break;
