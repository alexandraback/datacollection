#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Qualification Round
Problem D
Ominous Omino

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* the small dataset is easier than it appears...
	* you have to check these conditions:
		* is R*C a multiple of N
		* does there exist an N-omino that ....
	* for the easy case, I think you just return true if R*C is a multiple of N...?
	* conditions for small dataset:
		* R*C is a multiple of X
		* R > X or C > X


'''

################################################################################

from math import ceil, sqrt, floor

def read_case(id, input):
	X, R, C = [int(x) for x in input.readline().split()]
	return (X, R, C)

def solve(X,R,C):
	if ((R * C) % X) > 0: return False
	if (R < X) and (C < X): return False
	if (ceil(sqrt(X)) > R) and (floor(sqrt(X)) > R): return False
	if (ceil(sqrt(X)) > C) and (floor(sqrt(X)) > C): return False
	return True
	

def solve_case(id, case):
	X, R, C = case
	return "Case #{}: {}\n".format(id, 'GABRIEL' if solve(X,R,C) else 'RICHARD')


def prepare():
	def prepare_data():
		return None
	
	global prepared_data
	prepared_data = prepare_cached(prepare_data, 'prepared_data.cached')


################################################################################


from sys import stdin, stdout, stderr
import time
import math
import pickle
import io

execution_timer = time.time
#execution_timer = time.clock
debugging = 1


################################################################################


def debug(message):
	if debugging:
		stderr.write(message() if hasattr(message, '__call__') else message)

def report(message):
	stderr.write(message)

def prepare_cached(prepare_data, pickle_path='data.pickle'):
	try:
		data = pickle.load(io.open(pickle_path, 'rb'))
		report("Loaded {}.\n".format(pickle_path))
	except IOError:
		data = prepare_data()
		report("Prepared {}.\n".format(pickle_path))
		pickle.dump(data, io.open(pickle_path, 'wb'))
	return data

def main():
	t0 = execution_timer()
	prepare()
	t1 = execution_timer()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(stdin.readline())
	for case_id in range(1,T+1):
		report("Processing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(case_id, T, case_id-1, execution_timer() - t1))
		report("\n" if debugging else "\r")
		stderr.flush()
		stdout.write(solve_case(case_id, read_case(case_id, stdin)))
		stdout.flush()
	
	t2 = execution_timer()
	report("Processed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

if __name__ == '__main__':
	main()

