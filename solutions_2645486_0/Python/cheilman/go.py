#!/usr/bin/python

import sys
import math

def readfile(file):
  """
    input:

  """

  tests = []

  T = int(file.readline().strip())

  for i in xrange(T):
		line = file.readline().strip()

		E,R,N = line.split(" ")

		E = int(E)
		R = int(R)
		N = int(N)

		line = file.readline().strip()

		v = line.split(" ")
		v = [int(x) for x in v]

		test = (E, R, N, v)

		tests.append(test)

  return tests

def runHelper(Emax, E, R, N, v):
	"""
		Run a subtest.  Return the best value.
	"""

	best = 0

	for e in xrange(0, E + 1):
		val = v[0] * e
		left = E - e + R
		if left > Emax:
			left = Emax

		if len(v) > 1:
			vmore = runHelper(Emax, left, R, N, v[1:])
			val = val + vmore

		if val > best:
			best = val

	return best

def run(test):
	"""
		Run a test and return output.
	"""

	E,R,N,v = test

	if R >= E:
		# use it all
		val = 0
		for i in v:
			val = val + E * i
		return val

	return runHelper(E, E, R, N, v)

	pass

file = open(sys.argv[1], "rt")

tests = readfile(file)

file.close()

case = 1

#for test in (tests[0], tests[1], tests[2]):
for test in tests:
#if True:
	#test = tests[1]
	result = run(test)
	print "Case #%d: %s" % (case, result)
	case = case + 1
