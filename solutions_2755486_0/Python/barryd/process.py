#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2013
Round 1C
Problem C
The Great Wall

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* can we do this as a simple simulation?  Let's see
	* I think a simple simulation will be fine for the small dataset
		* 10 tribes * 10 attacks = 100 attacks
		* the interval size is at most 200, so we *could* use a simple array to represent the wall heights (be careful around index 0 - be sure it's from 0 to 1?)
		* 100 attacks * 200 entries = 20000 iterations
	* seems the problem is integral, so we don't have to worry about large values (well, most likely not)
	* let's try solve the small dataset in the time available
	* data representation:
		* use a dict to represent the wall heights (defaultdict)
		* push the attacks into a queue and sort (no point to use priority queue, since we only need sort once)

'''

################################################################################


class Tribe:
	def __init__(self, input):
		self.d, self.n, self.w, self.e, self.s, self.delta_d, self.delta_p, self.delta_s = [int(x) for x in input.readline().split()]

def read_case(id, input):
	N = int(input.readline())
	tribes = []
	for i in range(N):
		tribes.append(Tribe(input))
	return (N, tribes)

def solve_case(id, case):
	N, tribes = case
	
	attacks = defaultdict(list)
	for tribe in tribes:
		d = tribe.d
		w = tribe.w
		e = tribe.e
		s = tribe.s
		for i in range(tribe.n):
			attacks[d].append((w, e, s))
			d += tribe.delta_d
			w += tribe.delta_p
			e += tribe.delta_p
			s += tribe.delta_s
	
	wall = defaultdict(int)
	
	breaches = 0
	
	for d in sorted(attacks.keys()):
		for (w, e, s) in attacks[d]:
			breach = False
			for p in range(w, e):	# note: deliberately excluded e
				if wall[p] < s: breach = True
			if breach: breaches += 1
		for (w, e, s) in attacks[d]:
			for p in range(w, e):	# note: deliberately excluded e
				if s > wall[p]: wall[p] = s
	
	return "Case #{}: {}\n".format(id, breaches)


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

