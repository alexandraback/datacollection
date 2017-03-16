#!/usr/bin/python
# I recommend using "PyPy" instead, it's a lot faster on algorithmic code

import sys, multiprocessing

def inherits(klass1, klass2, diagram):
	if klass2 == klass1:
		return 1
	r = 0
	for k2 in diagram[klass1]:
		r += inherits(k2, klass2, diagram)
	return r

# The real algorithm starts here:
def main(d):
	for klass in xrange(d['n_classes']):
		for klass2 in xrange(d['n_classes']):
			if klass == klass2:
				continue
			if inherits(klass, klass2, d["inherits"]) > 1:
				return "Yes"
	return "No"


def parse_input():
	# The input is parsed into a list of dictionaries, one for each test case
	data = []
	n = int(sys.stdin.readline())
	for i in xrange(n):
		d = dict()
		
		d['n_classes'] = int(sys.stdin.readline())
		d['inherits'] = []
		for i in xrange(d['n_classes']):
			row = map(lambda x: int(x)-1, sys.stdin.readline().split("\n")[0].split())[1:]
			d['inherits'].append(row)

		data.append(d)
	return data


if __name__ == '__main__':
	data = parse_input()
	# Taking advantage of multi-core systems
	#pool = multiprocessing.Pool(processes=multiprocessing.cpu_count())
	#for n, result in enumerate(pool.map(main, data)):
	for n, d in enumerate(data):
		result = main(d)
		print("Case #" + str(n+1) + ": " + str(result))
