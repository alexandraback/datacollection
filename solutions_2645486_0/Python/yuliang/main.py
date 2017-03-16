#!/usr/bin/env python

# standard library imports
from contextlib import closing
import sys

def find_all_spending(E, R, N, reamin_energy, history, result):

	if len(history) == N:
		result.append(history)
		return

	if len(history) == N - 1:
		result.append(history[:] + [reamin_energy])
		return

	for i in xrange(0, reamin_energy + 1):
		if reamin_energy - i + R > E:
			continue

		find_all_spending(E, R, N, reamin_energy - i + R, history[:] + [i], result)

def solve(E, R, N, values):

	all_spending = []
	find_all_spending(E, R, N, E, [], all_spending)
	#print all_spending

	max_sum = 0
	for spending in all_spending:
		s = sum(map(lambda (i, v): i * v, zip(spending, values)))
		if s > max_sum:
			max_sum = s

	return max_sum

def main(argv):

    if len(argv) != 2:
        print  'usage: python %s input' % argv[0]
        exit(1)

    with closing(open(argv[1], 'r')) as f:
        input_data = f.read()

    input_data = input_data.split('\n')
    num_test = int(input_data[0])
    for i in xrange(1, num_test + 1):
    	ern = input_data[i * 2 - 1]
    	values = input_data[i * 2]

    	E, R, N = map(int, ern.split(' '))
    	values = map(int, values.split(' '))
    	#print 'E =', E, ', R =', R, ', N =', N
    	#print 'values =', values
    	print 'Case #%s: %s' % (i, solve(E, R, N, values))

if __name__ == "__main__":
    main(sys.argv)
