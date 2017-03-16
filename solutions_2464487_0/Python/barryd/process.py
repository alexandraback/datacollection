#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2013
Round 1A
Problem A
Bullseye

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* 6000 test cases
	* 1 ml paint covers pi cm**2
		area = paint * pi
		paint = area / pi
	* area(r) = pi * (r+1)**2 - pi * r**2
		= pi * ((r+1)**2 - r**2)
		= pi * (r**2 + 2r + 1 - r**2)
		= pi * (2r + 1)
	* b_area(r, n) = area of a bullseye of inner radius r with n rings
		b_area(r, 0) = 0
		b_area(r, n) = pi * (2*r + 1) + b_area(r + 2, n-1)
		b_paint(r, n) = (2*r + 1) + b_paint(r + 2, n-1)
		 = n + (2*r + 2*(r+2) + 2*(r+4) + ...)
		 = n + 2 * (r + r+2 + r+4 + ... r+2*n)
		 = n + 2 * (n * r + (0 + 2 + 4 + ... + 2*n))
		 = n + 2 * (n * r + ( 2 * (1 + 2 + 3 + ... + n) ))
		 = n + 2 * (n * r + ( 2 * (n**2 / 2) ))
	* working out n:
		paint = n + 2 * (n * r + ( 2 * (n**2 / 2) ))
		paint - n = 2 * (n * r + ( 2 * (n**2 / 2) ))
		(paint - n) / 2 = n * r + ( 2 * (n**2 / 2) )
		((paint - n) / 2) - (n * r) = n**2
		n**2 + r*n - (paint-n) / 2 = 0
		n**2 + r*n + n/2 - paint/2 = 0
		n**2 + (r + 1/2) * n - paint / 2 = 0
	* looks like a quadratic, but I'm suspicious, since a quadratic would have 2 answers and I didn't expect that to be the case with this problem
	* also, lots of room for error in that above algebra
	* checking over my math (doing it again):
		
		area(r) = pi * (r+1)**2 - pi * r**2
		= pi * ((r+1)**2 - r**2)
		= pi * (r**2 + 2 * r + 1 - r**2)
		= pi * (2 * r + 1)
		barea(r, n) = area(r) + area(r+2) + ... area(r+(2*(n-1)))
		= pi * (
			(2 * (r + 2 * 0) + 1) + (2 * (r + 2 * 1) + 1) + ... + (2 * (r + 2 * (n-1)) + 1)
		)
		= pi * (
			n + 2 * (
				r + 2 * 0 +
				r + 2 * 1 +
				...
				r + 2 * (n-1)
			)
		)
		= pi * (
			n + 2 * (
				r * n + 2 * (
					0 + 1 + ... + (n-1)
				)
			)
		)
		= pi * (
			n + 2 * (
				r * n + 2 * (
					(n-1 * n) / 2
				)
			)
		)
		= pi * (
			n + 2 * (
				r * n + 2 * (
					(n**2 - n) / 2
				)
			)
		)
		= pi * (
			n + 2 * (
				r * n + (n**2 - n)
			)
		)
		= pi * (
			n + 2 * (
				r * n + (n**2 - n)
			)
		)
		= pi * (n + 2 * r * n + 2 * n**2 - 2 * n)
		= pi * (n + 2 * r * n + 2 * n**2 - 2 * n)
		= pi * ( 2 * n**2 + (2*r - 1) * n )
		bpaint(r,n) = barea(r,n) / pi
		= ( 2 * n**2 + (2*r - 1) * n )
		bpaint = 2 * n**2 + (2*r - 1) * n
		2 * n**2 + (2*r - 1) * n - bpaint = 0
	
	* this is failing on the last test case, getting 50 instead of 49
	* I'm guessing that's floating point error, and this will work on the small dataset

'''

################################################################################

def solve_quad(a,b,c):
	#report("a {} b {} c {}\n".format(a,b,c))
	v1 = math.sqrt(b**2 - 4 * a * c)
	a1 = ((-b) + v1) / (2*a)
	a2 = ((-b) - v1) / (2*a)
	# no time to think about the meaning of the 2 results here
	# math domain error... means square root of a negative I guess?  Argh! have to check my math??
	return max(a1, a2)

def read_case(id, input):
	r, t = [int(n) for n in input.readline().split()]
	return (r, t)

def solve_case(id, case):
	r, t = case
	
	# 2 * n**2 + (2*r - 1) * n - t = 0
	solution = math.floor(solve_quad(2, 2 * r - 1, -t))
	
	return "Case #{}: {}\n".format(id, solution)


def prepare():
	pass


################################################################################

import sys
import time
import math
import pickle
import io
import multiprocessing
import queue

debugging = 0
num_workers = 1

def debug(message):
	if debugging: sys.stderr.write(message)

def report(message):
	sys.stderr.write(message)

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
	t0 = time.time()
	prepare()
	t1 = time.time()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(sys.stdin.readline())
	for case_id in range(1, T+1):
		cases.put((case_id, Case(case_id, sys.stdin)))
	
	workers = [Worker() for i in range(num_workers)]
	for worker in workers:
		worker.start()
	
	# harvest results
	results = [None] * T
	result_count = 0
	next_result = 0
	while next_result < T:
		report("\rProcessing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(result_count + 1, T, next_result + 1, time.time() - t1))
		sys.stderr.flush()
		case_id, output = outputs.get()
		result_count += 1
		results[case_id - 1] = output
		while next_result < T and results[next_result] != None:
			sys.stdout.write(results[next_result])
			sys.stdout.flush()
			next_result += 1
	
	for worker in workers:
		worker.join()
	
	t2 = time.time()
	report("\rProcessed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

def main_single():
	t0 = time.time()
	prepare()
	t1 = time.time()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(sys.stdin.readline())
	for case_id in range(1,T+1):
		report("\rProcessing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(case_id, T, case_id-1, time.time() - t1))
		sys.stderr.flush()
		sys.stdout.write(Case(case_id, sys.stdin).solve())
		sys.stdout.flush()
	
	t2 = time.time()
	report("\rProcessed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

if __name__ == '__main__':
	if num_workers == 1:
		main_single()
	else:
		main_parallel()

