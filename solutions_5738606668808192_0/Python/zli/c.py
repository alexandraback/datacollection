# https://pypi.python.org/pypi/pyprimes/
import pyprimes

def xl(l):
    return xrange(len(l))

#for case in range(1, input()+1):
for case in range(1, 2):
    print "Case #%s:" % (case)
    N, J = 16, 50
    #N, J = 6, 3
    count = 0
    #primes = list(pyprimes.primes_below(10 ** (N/2) + 2))
    #print len(primes)
    for i in range(1 << (N-2)):
        s = "1%s1" % bin(i)[2:].zfill(N-2)
        divisors = []
        for base in range(2, 11):
            number = int(s, base)
            sqrt_number = number ** 0.5
            for prime in pyprimes.primes_below(10 ** (N/2) + 2):
                if number % prime == 0:
                    divisors.append(prime)
                    break
                if prime > sqrt_number:
                    break
            #print divisors, base
            if len(divisors) < base-1:
                #print "%s is prime in base %s" % (s, base)
                break
        else:
            print s, " ".join(map(str, divisors))
            count += 1
            if count == J:
                break
    else:
        print "Error! Not enough jamcoins."
