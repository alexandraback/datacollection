#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2013
Round 1A
Problem B
Manage Your Energy

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* clearly you would like to combine the largest energy use with the most valuable activities
	* in fact, if there's a more valuable activity later, it always makes sense to expend 0 energy on the current activity, right?
	* iterate over activities from the beginning
	* if the current activity is the biggest before the end, expend all energy, else expend none
	* maybe working from the end would be faster, and using E + index * R to calculate the available energy at that point
		* but if there was a more valuable activity earlier, we would have consumed some of that energy
	* how about this:
		run through the activities and mark the energy you would have at that time if you hadn't spent any
		sort the activities in decreasing order of value
		set energy_consumed to 0
		for each activity in the sorted list, from beginning to end:
			available_energy = activity.energy - energy_consumed
			gain += available_energy * activity.value
			energy_consumed += available_energy
	* that should do it?
	* shit... all reasoning above doesn't account for the maximum energy limit
	* okay, slight adjustment...
	* energy_consumed *still* represents energy consumed on more important tasks
	* instead of assuming we have E+i*R - energy_consumed energy at a given activity, we'll assume we have min(E+i*R - energy_consumed, E)
	* I think that's it?
	* hard to reason about... let's just try it
	* do we have to care about which activity energy was consumed on?
	* we can view the energy available at each point as an array
	* when we consume energy, we reduce the energy for all prior 
	
	* when we use energy, we always reduce it to 0? no...
	* when we use energy, we always reduce it to 0 if you also count future energy usage as used...
	* how about we build up a sorted (by index) list of processed activities?
		* we can check how much energy we need by the next already-processed activity
		* multiply R by the difference between the indices
		* 
	* in an optimal strategy, energy used at the most valuable will definitely be E
	* at the next most valuable:
		if before the most valuable:
			min(E, R * index_diff)
		if after the most valuable:
			min(E, R * index_diff)
	* when consuming energy for the "most valuable so far":
		we always consume all energy (E), or at least, the most energy we can without disturbing already-processed (more valuable) activities
		so when we process one between 2, 
			3, 1, 2		=> 
			2, 1, 3		=> 
	* not sure about this, but I think we need to apply a limit based on the previous (by index) and the next (by index) activities

'''

################################################################################


class Activity:
	def __init__(self, index, value):
		self.index = index
		self.value = value
		self.consumed = None
	
	def __repr__(self):
		return "(i{} v{} c{})".format(self.index, self.value, self.consumed)

def read_case(id, input):
	E, R, N = [int(n) for n in input.readline().split()]
	activities = [Activity(i, int(val)) for (i, val) in enumerate(input.readline().split())]
	return (E, R, N, activities)

from bisect import bisect_left, bisect_right

def solve_case(id, case):
	E, R, N, activities = case
	
	# we already assigned indexes during construction
	
	activities = sorted(activities, key=lambda a: a.value, reverse=True)
	
	report("{}\n".format(activities))
	
	'''
		run through the activities and mark the energy you would have at that time if you hadn't spent any
		sort the activities in decreasing order of value
		set energy_consumed to 0
		for each activity in the sorted list, from beginning to end:
			available_energy = activity.energy - energy_consumed
			gain += available_energy * activity.value
			energy_consumed += available_energy
			
		* instead of assuming we have E+i*R - energy_consumed energy at a given activity, we'll assume we have min(E+i*R - energy_consumed, E)
	'''
	gain = 0
	energy_consumed = 0
	ordered = []
	for activity in activities:
		# bisect_left(a, x[, lo[, hi]]) -> index
		# no key= for bisect, and no time for a workaround!
		# this is less than optimal
		ordered.append(activity)
		ordered = sorted(ordered, key=lambda a: a.index)
		oindex = ordered.index(activity)
		
		potential_energy = E + activity.index * R
		available_energy = min(potential_energy, E)
		
		if (oindex > 0):
			available_energy = min(available_energy, (activity.index - ordered[oindex-1].index) * R)
		if (oindex < (len(ordered)-1)):
			available_energy = min(available_energy, (ordered[oindex+1].index - activity.index) * R)
		
		gain += available_energy * activity.value
		energy_consumed += available_energy
		report("E {} R {} i {} pe {} ae {} ec {}\n".format(E, R, activity.index, potential_energy, available_energy, energy_consumed))
		activity.consumed = available_energy
		
	
	report("\nresult {}: {}\n".format(id, sorted(activities, key=lambda a: a.index)))
	
	#report("con {}, total {}\n".format(energy_consumed, E + R * (N-1)))
	
	return "Case #{}: {}\n".format(id, gain)


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

