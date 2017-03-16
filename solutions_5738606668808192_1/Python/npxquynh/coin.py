import numpy
import random

from pdb import set_trace as debugger

fi = open('small.in')
# fi = open('small2.in')
fi = open('C-large.in', 'r')
fo = open('cresult.out', 'w')

T = int(fi.readline())
fo.write('Case #%i:\n' % (T))


found_coins = list()
failed_coins = 0

def primesfrom3to(n):
    """ Returns a array of primes, 3 <= p < n """
    sieve = numpy.ones(n/2, dtype=numpy.bool)
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i/2]:
            sieve[i*i/2::i] = False
    return 2*numpy.nonzero(sieve)[0][1::]+1

primes = primesfrom3to(pow(10, 8))

def base10toN(num,b):
   return ((num == 0) and  "0" ) or ( base10toN(num // b, b).lstrip("0") + "0123456789abcdefghijklmnopqrstuvwxyz"[num % b])



def generate_coin(N):
    # randomize some number
    return_val = False
    binary_coin = 0
    divisors = list()

    smallest_num = pow(2, N-1)
    largest_num = pow(2, N) - 1

    while (return_val is False):
        n = 0
        while(n % 2 == 0):
            n = random.randint(smallest_num, largest_num)

            if n in found_coins: # to randomize another coin
                n = 0

        binary_n = bin(n)[2:]
        # binary_coin = '1001'
        divisors = find_all_number_in_different_base(binary_n)

        if divisors is None:
            failed_coins = 0
        else:
            return n, divisors

def find_all_number_in_different_base(binary_n):
    divisors = []
    bases = [b for b in range(2, 11)]
    for b in bases:
        num_in_base_10 = int(binary_n, b)
        d = non_trivial_divisor(num_in_base_10)
        if d is None:
            return None
        else:
            divisors.append(d)

    return divisors

def non_trivial_divisor(num):
    if num % 2 == 0:
        return 2

    for p in primes[:500]:
        if p >= num:
            break
        if num % p == 0:
            return p

    print "        possible prime: %s" % num
    return None


for t in range(1, T+1):
    N, J = [int(c) for c in fi.readline().strip().split(' ')]

    # for b in range(2, 11):
    #     binary_n = '1001'
    #     num_in_base_10 = int(binary_n, b)
    #     print 'Base #%i:  %s' % (b, num_in_base_10)


    for j in range(J):
        print 'j = %i' % j
        coin, divisors = generate_coin(N)
        found_coins.append(coin)

        print '%s ' % bin(coin)[2:]
        print '%s\n' % ' '.join([str(d) for d in divisors])
        fo.write('%s ' % bin(coin)[2:])
        fo.write('%s\n' % ' '.join([str(d) for d in divisors]))

    # generate_coin(N, J)