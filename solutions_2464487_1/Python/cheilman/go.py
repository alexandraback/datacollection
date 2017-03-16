#!/usr/bin/python

import sys
import math

def readfile(file):
  """
    input:

		The first line of the input gives the number of test
		cases, T. T test cases follow. Each test case consists of
		a line containing two space separated integers: r and t.

		T
		r t
		...

  """

  tests = []

  T = int(file.readline().strip())

  for i in xrange(T):
		line = file.readline().strip()
		r,t = line.split(" ")

		tests.append((int(r),int(t)))

  return tests

def real_quad(a,b,c):
	"""
		Return only real roots to the quadratic eq. ax^2 + bx + c.
	"""

	discriminant = (b * b) - (4 * a * c)

	if (discriminant > 0):
		sqrtDisc = math.sqrt(discriminant)

		return ( ((-1 * b + sqrtDisc) / (2 * a)), ((-1 * b - sqrtDisc) / (2 * a)) )
	elif discriminant == 0:
		return (0,)
	else:
		return ()

def paint(b, r):
	"""
		Return the amount of paint needed to put b black bands, starting
		with white radius r.
	"""

	return 2 * b * b + b * (2 * r - 1)

def run(test):
	"""
		Run a test and return output.
	"""

	black_count = 0
	r = test[0]
	t = test[1]

	#roots = real_quad(2, r, -1 * t)
	roots = real_quad(2, 2 * r - 1, -1 * t)

	sln = int(max(roots))

	#print "r = %d, t = %d, sln = %d" % (r, t, sln)

	# For some reason this is failing to give the right answer
	# for a sample value.  This should fake it being okay (off by one)
	# Start with the root, get the paint needed.  If it's too much, work
	# our way down.

	needed = paint(sln, r)

	while (needed > t) and (sln > 0):
		sln = sln - 1
		needed = paint(sln, r)

	return sln

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
