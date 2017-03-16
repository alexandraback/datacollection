import math
import numpy

FILE_NAME = 'primes.tmp'

def prepare_primes_file(n):
    # Input n>=6, Returns a array of primes, 2 <= p < n
    sieve = numpy.ones(n/3 + (n%6==2), dtype=numpy.bool)
    for i in xrange(1,int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[       k*k/3     ::2*k] = False
            sieve[k*(k-2*(i&1)+4)/3::2*k] = False
    with open(FILE_NAME, 'w') as f:
        f.write('2\n3\n')
        for i in numpy.nonzero(sieve)[0][1:]:
            f.write('{0}\n'.format((3*i+1)|1))

def prepare_from_file():
    primes = {}
    with open(FILE_NAME, 'r') as f:
        for line in f:
            primes[int(line)] = None
    return primes

def prepare_in_mem(n):
    """ Input n>=6, Returns a array of primes, 2 <= p < n """
    sieve = numpy.ones(n/3 + (n%6==2), dtype=numpy.bool)
    for i in xrange(1,int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[       k*k/3     ::2*k] = False
            sieve[k*(k-2*(i&1)+4)/3::2*k] = False
    primes = {}
    for i in numpy.r_[2,3,((3*numpy.nonzero(sieve)[0][1:]+1)|1)]:
        primes[i] = None
    return primes

# prepare_primes_file(2**32)
# cache = prepare_from_file()
cache = prepare_in_mem(2*16)

def largest_prime_factor(n):
    if n in cache:
        return cache[n]
    max_prime = min(int(math.sqrt(n)), 10000)
    for i in xrange(2, max_prime+1):
        if (n % i) == 0:
            cache[n] = i
            return i
    cache[n] = None
    return None

def int2str_with_base(num,b,numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
    return ((num == 0) and numerals[0]) or (int2str_with_base(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])


# smallest jamcode is 3, as "11"
def solve(n, j):
    """
    num: jamcode in base 10. In range [2**(n-1)+1, 2**n-1]
    inside: jamcode without leading/tail digit 1 in base 10. In range [0, 2**(n-2)-1]
    """
    print n, j
    min_num = 2**(n-1) + 1 # 1000..01
    max_inside = 2**(n-2) - 1 #111..1
    result = []
    current_inside = -1
    for i in xrange(j):
        new_result = [None] * 10

        while current_inside < max_inside:
            current_inside += 1
            num = min_num + 2 * current_inside
            num_str = int2str_with_base(num, 2)
            print 'num_str', num_str
            new_result[0] = num_str
            has_prime = False
            for base in xrange(2,11):
                num_in_base = int(num_str, base)
                factor = largest_prime_factor(num_in_base)
                print 'num', num_in_base, base, factor
                if not factor:
                    has_prime = True
                    break
                new_result[base - 1] = str(factor)
            print new_result, has_prime
            if not has_prime:
                break

        if current_inside >= max_inside:
            print "ERROR"
            return

        print new_result
        result.append(" ".join(new_result))
    return "\n".join(result)

with open('coinjam.in', 'r') as fin:
    with open('coinjam.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            N, J = map(int, fin.readline().split())
            fout.write('Case #{0}:\n{1}\n'.format(i, solve(N, J)))
