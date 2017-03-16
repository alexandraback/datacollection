#!/usr/bin/env python

# standard library imports
from contextlib import closing
import sys

def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

def solve(r, t):

	k =  (2 * r - 1)
	return int((isqrt(k * k + 8 * t) - k) / 4)

def main(argv):

    if len(argv) != 2:
        print  'usage: python %s input' % argv[0]
        exit(1)

    with closing(open(argv[1], 'r')) as f:
        input_data = f.read()

    input_data = input_data.split('\n')
    num_test = int(input_data[0])
    for i in xrange(1, num_test + 1):
    	test = input_data[i]
    	r, t = map(int, test.split(' '))
    	print 'Case #%s: %s' % (i, solve(r, t))

if __name__ == "__main__":
    main(sys.argv)
