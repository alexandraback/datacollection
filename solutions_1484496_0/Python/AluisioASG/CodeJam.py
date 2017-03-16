# -*- coding: utf-8 -*-
# Google Code Jam - General utilities
# http://code.google.com/codejam/
# Copyright © 2012 Aluísio Augusto Silva Gonçalves
# This module is free software, licensed under the terms of the Artistic License 2.0


# Imports {{{1
##############

from __future__ import print_function, unicode_literals

import fileinput
import functools
import sys

if sys.platform == 'win32':
	from time import clock as time
else:
	from time import time


__all__ = ['TestCase', 'ProblemSolver']


# Test cases {{{1
#################

class TestCase(object):
	_next_id = 1

	def __init__ (self, _=None):
		self.id = self.__class__._next_id
		self.solution = None
		self.input = []
		self.__class__._next_id += 1

	def __hash__ (self):
		return self.id

	def solve (self, solver):
		""" Solve the test case by running the solver on the case's input. """
		self.solution = solver(self.input)
		return self

	@classmethod
	def parseInput (cls, file, lines):
		""" Get test cases, reading the specified number of lines of input for each one. """
		cases = []
		for _ in range(int(file.readline().strip())):
			case = cls()
			for _ in range(lines):
				case.input.append(file.readline().rstrip('\n'))
			cases.append(case)
		return cases


# Processing {{{1
#################

def processCases (cases, solver):
	""" Solve the test cases, one at a time. """
	return [case.solve(solver) for case in cases]

def processCasesAsyncMP (cases, solver):
	""" Solve the test cases, asynchronously, using multiple processes. """
	# XXX: Broken on Linux
	import multiprocessing
	pool = multiprocessing.Pool(5)
	solver = functools.partial(TestCase.solve, solver=solver)
	results = pool.map_async(solver, cases)
	results.wait()
	return results.get()

def processCasesAsyncF (cases, solver):
	""" Solve the test cases, asynchronously, using concurrent.futures. """
	import concurrent.futures
	solver = functools.partial(TestCase.solve, solver=solver)
	with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
		futures = [executor.submit(solver, case) for case in cases]
	return [future.result() for future in concurrent.futures.as_completed(futures)]

def outputResults (cases):
	""" Print the cases' solutions, as required by the server. """
	for case in sorted(cases, key=lambda case: case.id):
		print("Case #{}: {}".format(case.id, case.solution))


# Entry point {{{1
##################

class ProblemSolver(object):
	def __init__ (self, module_name, test_case_class=TestCase, **input_parser_args):
		self.autorun = (module_name == '__main__')
		self.test_case_class = test_case_class
		if input_parser_args:
			self.test_case_class.parseInput = (
				functools.partial(self.test_case_class.parseInput,
				                  **input_parser_args))

	def __call__ (self, func):
		self.solver = func
		self.__call__ = self.run
		if self.autorun: self.run()

	def run (self):
		# Read inputs
		start = time()
		cases = self.test_case_class.parseInput(fileinput.input())
		end = time()
		print("Input reading time: {} seconds".format(end - start), file=sys.stderr)

		# Get solutions
		start = time()
		results = processCases(cases, self.solver)
		end = time()
		print("Data processing time: {} seconds".format(end - start), file=sys.stderr)

		# Print outputs
		start = time()
		outputResults(results)
		end = time()
		print("Output processing time: {} seconds".format(end - start), file=sys.stderr)


# Miscellaneous {{{1
####################

Py3k = (sys.hexversion >= 0x3000000)
