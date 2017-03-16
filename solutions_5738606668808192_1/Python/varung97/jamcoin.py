import sys, time

start = time.time()

def read_primes():
    primes = sys.stdin.readlines()
    return [int(prime) for prime in primes]

def is_composite(num):
    for prime in primes:
        if prime == num:
            return 0
        if num % prime == 0:
            return prime
    return 0

primes = read_primes()
count = 0

print "Case #1:"

for num in range(2147483649, 4294967296, 2):
# for num in range(32769, 65536, 2):
# for num in range(2, 100):
    strRep = bin(num)[2:]
    is_jamcoin = True
    divs = []
    for base in range(2, 11):
        baseRep = int(strRep, base)
        div = is_composite(baseRep)
        if not div:
            is_jamcoin = False
            break
        else:
            divs.append(div)
    if is_jamcoin:
        print strRep, str(divs)[1:-1].replace(',', '')
        count += 1
        if count == 500:
            break
