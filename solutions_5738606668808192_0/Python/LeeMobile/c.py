import sys


PRIMES = [
      2,    3,      5,      7,     11,     13,     17,     19,     23,     29,
     31,     37,     41,     43,     47,     53,     59,     61,     67,     71, 
     73,     79,     83,     89,     97,    101,    103,    107,    109,    113, 
    127,    131,    137,    139,    149,    151,    157,    163,    167,    173, 
    179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
    233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
    283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
    353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
    419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
    467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
    547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
    607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
    661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
    739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
    811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
    877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
    947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013, 
   1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069, 
    ]


f = open(sys.argv[1])
lines = f.readlines()[1:]


print "Case #1:"


def create_binary(number):
    return "{0:b}".format(number)


def binary_to_number(binary, base):
    length = len(binary)
    ret = 0
    for i, b in enumerate(binary):
        ret += (int(b) * (base ** (length - i - 1)))
    return ret


def find_prime_multiple(number):
    for p in PRIMES:
        if p >= number:
            break
        if number % p == 0:
            return p
    return 0


def get_divisors(coin):
    divisors = []

    for i in range(2, 11):
        value = binary_to_number(coin, i)
        prime_multiple = find_prime_multiple(value)
        if prime_multiple:
            divisors.append(prime_multiple)
        else:
            break
    return divisors


def next_coin(coin):
    number = binary_to_number(coin[1:-1], 2)
    number += 1
    binary = create_binary(number)
    padding = len(coin) - len(binary) - 2
    return "1" + "0" * padding + binary + "1"


for index, line in enumerate(lines):
    N, J = map(int, line.strip().split())
    coin = '1' + '0' * (N-2) + '1'
    count = 0

    while count < J:
        divisors = get_divisors(coin)
        if len(divisors) == 9:
            count += 1
            ds = map(str, divisors)
            print "%s %s" % (coin, " ".join(ds))
        coin = next_coin(coin)
