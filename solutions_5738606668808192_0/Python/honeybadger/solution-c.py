"""
Created on Apr 8, 2016

@author: umnik700@gmail.com
"""
from itertools import product


# INPUT_FILE = 'test-input.txt'
# OUTPUT_FILE = 'test-output.txt'
PRIMES_SET = set()
PRIMES = []

INPUT_FILE = 'C-small-attempt0.in'
OUTPUT_FILE = 'C-small-attempt0.out'

# INPUT_FILE = 'C-large.in'
# OUTPUT_FILE = 'C-large.out'

def get_primes(n):
    result = []
    s = [True] * (n/2)
    for i in xrange(3, int(n**0.5)+1, 2):
        if s[i/2]:
            s[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    result += [2*i+1 for i in xrange(1, n/2) if s[i]]
    return result

def is_prime_in_base(s, base):
    global PRIMES_SET
    global PRIMES

    v = int(s, base)
    if(v in PRIMES_SET):
        return True, None
    
    for i in PRIMES:
        if(i >= v):
            break

        if((v % i) == 0):
            return False, i

    # this might not really be a prime
    # but it is a shortcut we take here
    return True, None


def process_case(n, j):
    global PRIMES_SET
    global PRIMES

    result = []

    # primes under 1,000,000
    PRIME_LIMIT = 1000000
    PRIMES = get_primes(PRIME_LIMIT)
    PRIMES_SET = set(PRIMES)
    # print 'number of primes', len(PRIMES_SET)
    
    # first and last digit is 1
    # so our permutations should be
    # of N-2 length and then we add '1' 
    # at the beginning and end
    for i in product('10', repeat=(n - 2)):
        s = '1{0}1'.format(''.join(i))
        # print s

        divisors = []
        for x in xrange(2, 11):
            is_prime, d = is_prime_in_base(s, x)
            if(is_prime):
                continue

            divisors += [str(d)]
            # print 'divisors', divisors, 'len(divisors)', len(divisors)

        if(len(divisors) == 9):
            # this is the number that we want
            result += [[s] + divisors]
            # print len(result), [[s] + divisors]
            if(len(result) >= j):
                break

    return result


total_tests = None
tests = []

with open(INPUT_FILE, 'rU') as f:

    input_data = list(f)
    index = 0
    while index < len(input_data):

        print 'index', index
        line = input_data[index].strip()

        if(total_tests is None):
            total_tests = int(line)
            print 'total_tests', total_tests
            index += 1
            continue

        N, J = line.split(' ')
        tests += [(int(N), int(J))]
        index += 1

print tests
if(total_tests != len(tests)):
    print 'tests', len(tests)
    raise Exception('invalid number of tests')

print '-' * 70
print 'input data'
print '-' * 70
for test in tests:
    print test
print '-' * 70

case_number = 0

with open(OUTPUT_FILE, 'wb') as o:
    for n, j in tests:
        case_number += 1

        results = process_case(n, j)

        print "Case #{0}:".format(case_number)
        o.write("Case #{0}:\n".format(case_number))

        for result in results:
            print format(' '.join(result))
            o.write("{0}\n".format(' '.join(result)))
