import random
import math

def toBase10(num_str, base):
    return int(num_str, base)

def toBase2Str(num):
    return bin(num)[2:]

def genPrimes(n):
    """primes = [2]
    for i in range(3, n, 2):
        add = True
        for p in primes:
            if i % p == 0:
                add = False
                break
        if add:
            primes.append(i)
    return primes
    """
    return [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

for t in range(int(input().strip())):
    print('Case #%d:' % (t + 1))
    n, j = map(int, input().strip().split())
    primes = genPrimes(1000)
    count = 0
    for r in range(2 ** (n - 3)):
        s = '1' + ('000000000000000000000000000000' + toBase2Str(r))[- (n - 2): ] + '1'
        non_trivial = []
        for base in range(2, 11):
            val = toBase10(s, base)
            for p in primes:
                if p != val and val % p == 0:
                    non_trivial.append(p)
                    break
        if len(non_trivial) == 9:
            print(s, end = "")
            for v in non_trivial:
                print(" " + str(v), end = "")
            print("")
            count += 1
        if count >= j:
            break
