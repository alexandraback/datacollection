import sys
import random

def convert(bin, base):
    bin_str = "{0:b}".format(bin)
    result = 0
    for c in bin_str:
        result *= base
        result += int(c == '1')
    return result

num_to_divs = {}

def get_random_candidate(n):
    result = 1
    n -= 1
    while n > 1:
        result <<= 1;
        result += random.randint(0, 1)
        n -= 1

    return (result << 1) + 1

def maybe_find_min_divisor(n):
    MAGIC = 10000
    for i in xrange(2, MAGIC):
        if n % i == 0:
            return i
    return 0

def main():
    N = 32
    J = 500;
    while J > 0:
        candidate = get_random_candidate(N)
        print >> sys.stderr, "{0:b}".format(candidate)
        if candidate in num_to_divs:
            continue
        divs = []
        for i in xrange(2, 11):
            bic = convert(candidate, i)
            div = maybe_find_min_divisor(bic)
            if div == 0:
                break
            divs.append(div)
        if len(divs) != 9:
            continue
        num_to_divs[candidate] = divs
        J -= 1
        print >> sys.stderr, J
    print "Case #1:"
    for n, divs in num_to_divs.iteritems():
        print "{0:b}".format(n), " ".join(map(str, divs))

main()
