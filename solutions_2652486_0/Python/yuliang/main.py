#!/usr/bin/env python

# standard library imports
from contextlib import closing
import sys

def brute_forth():

	all_possible = {
		(2, 2, 2): (1, 2, 2, 2, 4, 4, 4, 8),
		(2, 2, 3): (1, 2, 2, 3, 4, 6, 4, 12),
		(2, 2, 4): (1, 2, 2, 4, 4, 8, 8, 16),
		(2, 2, 5): (1, 2, 2, 5, 4, 10, 10, 20),
		(2, 3, 3): (1, 2, 3, 3, 6, 9, 6, 18),
		(2, 3, 4): (1, 2, 3, 4, 6, 8, 12, 24),
		(2, 3, 5): (1, 2, 3, 5, 6, 15, 10, 30),
		(2, 4, 4): (1, 2, 4, 4, 8, 16, 8, 32),
		(2, 4, 5): (1, 2, 4, 5, 8, 20, 10, 40),
		(2, 5, 5): (1, 2, 5, 5, 10, 25, 10, 50),
		(3, 3, 3): (1, 3, 3, 3, 9, 9, 9, 27),
		(3, 3, 4): (1, 3, 3, 4, 9, 12, 9, 36),
		(3, 3, 5): (1, 3, 3, 5, 15, 9, 15, 45),
		(3, 4, 4): (1, 3, 4, 4, 12, 16, 12, 48),
		(3, 4, 5): (1, 3, 4, 5, 12, 15, 20, 60),
		(3, 5, 5): (1, 3, 5, 5, 15, 25, 15, 75),
		(4, 4, 4): (1, 4, 4, 4, 16, 16, 16, 64),
		(4, 4, 5): (1, 4, 4, 5, 16, 20, 16, 80),
		(4, 5, 5): (1, 4, 5, 5, 20, 20, 25, 100),
		(5, 5, 5): (1, 5, 5, 5, 25, 25, 25, 125),
	}

	guess = {}
	for key in all_possible:
		values = all_possible[key]
		for val in values:
			if val not in guess:
				guess[val] = set()

			guess[val].add(key)

	return guess

def main(argv):

    if len(argv) != 2:
        print  'usage: python %s input' % argv[0]
        exit(1)

    with closing(open(argv[1], 'r')) as f:
        input_data = f.read()

    input_data = input_data.split('\n')
    R, N, M, K = map(int, input_data[1].split(' '))
    #assert(R == 100 and N == 3 and M == 5 and K == 7)

    guess_dict = brute_forth()
    print 'Case #1:'

    for i in xrange(2, R + 2):
    	line = map(int, input_data[i].split(' '))
    	pp = guess_dict[1].copy()
    	solved = False

    	for j in line:
    		p = guess_dict[j]
    		pp = pp & p

    		if len(pp) == 1:
    			solved = True
    			break

    	print ''.join(map(str, pp.pop()))

if __name__ == "__main__":
    main(sys.argv)
