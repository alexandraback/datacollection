import math
import time
import sys

def get_divisor(N):
    for i in xrange(2, 1000): #int(math.sqrt(N))+1):
        if N % i == 0:
            return i
    return None

def create_divisor_map(start, end):
    divisor_map = {}
    for i in xrange(start, end):
        divisor_map[i] = get_divisor(i)
    return divisor_map

def get_base2_representation(number):
    return "{0:b}".format(number)

def get_divisors(number_string):
    divisors = []
    for i in xrange(2, 11):
        base_number = int(number_string, i)
        # if base_number in divisor_map:
        #     divisor = divisor_map[base_number]
        # else:
        divisor = get_divisor(base_number)
        if divisor is None:
            return None
        divisors.append(divisor)
    return divisors

if __name__ == '__main__':
    with open(sys.argv[1]) as fd:
        lines = fd.readlines()
    N, J = [int(i) for i  in lines[1].strip().split()]
    jamcoins_found = 0
    print 'Case #1:'
    smalles_number = int('1' + '0' * (N - 2) + '1', 2)
    largest_number_stripped = 2 ** (N -2)
    #divisor_map = {}# create_divisor_map(smalles_number, smalles_number + 2 ** 20)
    for i in xrange(0, largest_number_stripped):
        binary_representation = get_base2_representation(i)
        number_string = '%s%s%s%s' % ('1', '0' * (N -2 - len(binary_representation)), binary_representation, '1')
        divisors = get_divisors(number_string)
        if divisors:
            jamcoins_found += 1
            print number_string, ' '.join([str(divisor) for divisor in divisors])
        if jamcoins_found == J:
            break
