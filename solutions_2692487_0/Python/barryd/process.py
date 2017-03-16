#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2013
Round 1B
Problem A
Osmos

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* when removing a mote, always remove largest
	* when adding a mote, always add 1 unit smaller than the largest armin can reach
	* sort motes by size
	* consider remove and add operations in parallel...?
	* no... consider how many additional motes can be absorbed if we add one
	* and consider how many can be removed if we remove one (always 1)
	* so long as adding 1 allows us to absorb more than 1 more of the original motes, we do that
	* but we might have to add more than 1 before we can absorb more....
	* so we calculate at each step:
		* how many do we have to add before we can absorb original motes again
			* actually, this is not O(1)... so... I guess that's the trick of the large dataset
		* and how many original motes will we then be able to absorb
		* if the amount absorbed is larger than the amount of adds, we do that, otherwise we chop frmo the end
		* for N<=100, this will be fine
	* slight adjustment:
		* we compare between removing all motes to stop immediately, and adding motes to continue absorbing
	* no, it's harder than that...
		* at every point, we get a possible solution of amount added so far plus amount remaining
		* we have to keep comparing this to the current max
	
	* calculating the amount of motes needed to add:
		* depends on the next mote size
		* 

'''

################################################################################


def read_case(id, input):
	A,N = [int(x) for x in input.readline().split()]
	motes = [int(x) for x in input.readline().split()]
	return A,N,motes

def solve_case(id, case):
	A,N,motes = case
	
	motes = sorted(motes, reverse=True)
	steps = 0
	best = 100
	def register(s):
		nonlocal best
		if s < best:
			best = s
	
	register(steps + len(motes))
	while motes:
		if A <= 1:
			break
		
		# how many motes would we have to add to resume absorbing them?
		# for large dataset, we need to do this bit in more like O(1) time
		# change to a while for big set
		if A <= motes[-1]:
			A += A-1
			steps += 1
		else:
			A+= motes.pop()
		
		register(steps + len(motes))
	
	return "Case #{}: {}\n".format(id, best)


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
import multiprocessing
import queue

execution_timer = time.time
#execution_timer = time.clock
debugging = 1
num_workers = 1


################################################################################


def debug(message):
	if debugging:
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
				output = case.solve()
				outputs.put((id, output))
			except queue.Empty:
				return

class Case:
	def __init__(self, id, input):
		self.id = id
		self.case = read_case(self.id, input)
	
	def solve(self):
		return solve_case(self.id, self.case)

def prepare_cached(prepare_data, pickle_path='data.pickle'):
	try:
		data = pickle.load(io.open(pickle_path, 'rb'))
		report("Loaded {}.\n".format(pickle_path))
	except IOError:
		data = prepare_data()
		report("Prepared {}.\n".format(pickle_path))
		pickle.dump(data, io.open(pickle_path, 'wb'))
	return data

def main_parallel():
	t0 = execution_timer()
	prepare()
	t1 = execution_timer()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(stdin.readline())
	for case_id in range(1, T+1):
		cases.put((case_id, Case(case_id, stdin)))
	
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
		stdout.write(Case(case_id, stdin).solve())
		stdout.flush()
	
	t2 = execution_timer()
	report("Processed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

if __name__ == '__main__':
	if num_workers == 1:
		main_single()
	else:
		main_parallel()

