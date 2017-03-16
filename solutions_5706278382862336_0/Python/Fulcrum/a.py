from fractions import Fraction
from math import log

def read_ints(file, delimeter=None):
    line = file.readline().strip().split(delimeter)
    result = tuple(map(int, line))
    if len(result) == 1:
        result = result[0]
    return result


def input():
    filename = __file__.split('.')[0] + '.in'
    with open(filename) as file:
        tests_count = int(file.readline().strip())

        for test_index in xrange(tests_count):
            p, q = read_ints(file, '/')
            yield p, q

def output():
    filename = __file__.split('.')[0] + '.out'
    with open(filename, 'w') as file:
        i = 0
        while True:
            value = (yield)
            i += 1
            file.write('Case #%d: %s\n' % (i, value))


def main():
    results = output()
    results.next()

    for task in input():
        p, q = task
        fraction = Fraction(p, q)

        for i in xrange(41):
            if fraction.denominator == 2 ** i:
                answer = i - int(log(fraction.numerator, 2))
                results.send(answer)
                break
        else:
            results.send('impossible')

    results.close()

if __name__ == '__main__':
    main()
