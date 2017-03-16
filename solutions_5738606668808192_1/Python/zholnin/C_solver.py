
prime = []

def primes():
    global prime
    prime.append(2);
    for i in range(1, 100000):
        number = i * 2 + 1
        good = True
        for j in prime:
            if number % j == 0:
                good = False
                break
        if good:
            prime.append(number)


def check_prime(number):
    for j in prime:
        if j >= number:
            return 1
        if number % j == 0:
            return j
    return 1



import random

primes()

print "Case #1:"
used = set()

count = 0
while count < 500:
    b = "1" + "".join([random.choice(['0', '1']) for _ in range(30)]) + "1"
    if b in used:
        continue
    
    divisors = []
    
    for base in range(2, 11):
        number = int(b, base)
        divisor = check_prime(number)
        if divisor == 1:
            break
        else:
            divisors.append(divisor)
    
    if len(divisors) == 9:
        print b,
        for i in divisors:
            print i,
        print
        count += 1
        used.add(b)
