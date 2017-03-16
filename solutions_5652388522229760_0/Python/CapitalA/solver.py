import sys

def get_digits(number):
    number = int(number)
    digits = set()
    while number > 0:
        digits.add(number % 10)
        number = number / 10
    return digits

def solve_case(N):
    if N == 0:
        return 'INSOMNIA'
    n = N
    remaining_digits = set(xrange(10)).difference(get_digits(N))
    while len(remaining_digits):
        n += N
        remaining_digits = remaining_digits.difference(get_digits(n))
    return n

def main(filename):
    with open(filename, 'r') as fd:
        numbers = [int(line.strip()) for line in fd.readlines()]
    for i in xrange(1, len(numbers)):
        print 'Case #%d: %s' % (i, solve_case(numbers[i]))

if __name__ == '__main__':
    main(sys.argv[1])
