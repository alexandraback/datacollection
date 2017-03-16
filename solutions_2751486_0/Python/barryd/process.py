#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2013
Round 1C
Problem A
Consonants

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* for large dataset, names can be very big
	* the easy but slow way:
		* enumerate all substrings and check for the first consonant sequence of length n or greater
	* for each substring of length n, we have all the superstrings based on the start ranging from 0 to just before the substring, and the end ranging from just after the substring to the end of the name
	* okay, the fastest way:
		* first go forward and determine the lengths of consonant sequences, and their start position
		* for each, the number of n-length substrings is r-n+1 (where r is the length of the whole sequence)
		* for each n-length substring, the number of superstrings containing is (characters before + 1) * (characters after + 1)
			* but this will double-count some
		* perhaps we should just go dp on this problem to get an accurate, fast solution?
	* what if we work from the end of the last sequence (or the first position after the beginning of it)?
		* 
	* total substrings is start positions * end positions = approx. L**2 / 2
	* 

'''

################################################################################


def read_case(id, input):
	inline = input.readline().split()
	name = inline[0]
	n = int(inline[1])
	return (name, n)

def consonant(c):
	return c not in 'aeiou'

def solve_case(id, case):
	(name, n) = case
	
	sc = dict() # sc[i] substrings ending at i, containing an n-sequence
	s = dict() # substrings ending at i, not containing an n-sequence
	reps = dict() # probably doesn't need to be in an array... but won't hurt
	
	# n > 0, so 0-length string can't contain it
	reps[0] = 0
	sc[0] = 0
	s[0] = 1
	
	m = len(name)
	for i in range(1,m+1):
		reps[i] = (reps[i-1] + 1) if consonant(name[i-1]) else 0
		got = reps[i] >= n
		#debug("reps[{}] = {}\n".format(i, reps[i]))
		#debug("got[{}] = {}\n".format(i, got))
		
		sc[i] = s[i-n] if got else sc[i-1]
		s[i] = s[i-1] + 1
		
	
	solution = sum(sc.values())
	
	return "Case #{}: {}\n".format(id, solution)


def prepare():
	def prepare_data():
		return None
	
	global prepared_data
	#prepared_data = prepare_cached(prepare_data, 'prepared_data.cached')


################################################################################


from functools import reduce
from itertools import chain
from collections import defaultdict
from sys import stdin, stdout, stderr
import time
import math
import pickle
import io
import multiprocessing
import queue

execution_timer = time.time
#execution_timer = time.clock
debugging = 1
num_workers = 1


################################################################################


def debug(message, level=1):
	if debugging >= level:
		stderr.write(message() if hasattr(message, '__call__') else message)

def report(message):
	stderr.write(message)

cases = multiprocessing.Queue()
outputs = multiprocessing.Queue()
class Worker(multiprocessing.Process):
	def run(self):
		while True:
			try:
				id, case = cases.get_nowait()
				output = solve_case(id, case)
				outputs.put((id, output))
			except queue.Empty:
				return

def prepare_cached(prepare_data, pickle_path='data.pickle'):
	try:
		with io.open(pickle_path, 'rb') as file:
			data = pickle.load(file)
			report("Loaded {}.\n".format(pickle_path))
	except IOError:
		data = prepare_data()
		with io.open(pickle_path, 'wb') as file:
			pickle.dump(data, file)
	return data

def main_parallel():
	t0 = execution_timer()
	prepare()
	t1 = execution_timer()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(stdin.readline())
	for case_id in range(1, T+1):
		cases.put((case_id, read_case(case_id, stdin)))
	
	workers = [Worker() for i in range(num_workers)]
	for worker in workers:
		worker.start()
	
	# harvest results
	results = [None] * T
	result_count = 0
	next_result = 0
	while next_result < T:
		report("Processing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(result_count + 1, T, next_result, execution_timer() - t1))
		report("\n" if debugging else "\r")
		stderr.flush()
		case_id, output = outputs.get()
		result_count += 1
		results[case_id - 1] = output
		while next_result < T and results[next_result] != None:
			stdout.write(results[next_result])
			stdout.flush()
			next_result += 1
	
	for worker in workers:
		worker.join()
	
	t2 = execution_timer()
	report("Processed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

def main_single():
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
	if num_workers == 1:
		main_single()
	else:
		main_parallel()

