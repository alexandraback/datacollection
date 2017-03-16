#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Qualification Round
Problem B
Infinite House of Pancakes

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* the number of pancakes consumed per (non-special) minute is equal to the number of non-empty plates
	* there is never any advantage moving pancakes to a non-empty plate over an empty plate
	* moving always can and therefore always will (in optimal solution) increase the number of pancakes consumed per minute
	* there is never an advantage to eat first and then move, over moving and then eating
		* the number of pancakes consumed after a special minute can only be greater than before
	* we want to decrease the worst plate in any given special minute
	* it seems at first to make sense to always cut the biggest stack in half, but...
		* does this still hold if we want to take more than 1 turn to divide the stack by more than 2?
		* eg. we could spend 1 move to cut the biggest stack in 2
		* or 2 moves to cut the biggest stack in 3
		* or 3 moves to cut the biggest stack in 4
		* clearly if using 2 moves to cut it in 3, we won't divide it in half on the first cut
		* and if dividing it in 3 brings it down to the same level as all other stacks, we won't want to waste the extra turn to cut it in 4
		* so we cannot assume a stack is always halved
		* but we can divide a stack into k stacks in k-1 moves
	* taking the conclusions above into account, we can simplify the problem into an initial serving period composed entirely of special minutes, followed by an eating period composed entirely of special minutes
	* at any given time the biggest stack represents the number of additional minutes required to finish if we end the serving
	* naturally we only want to continue serving if we can improve upon that, even considering the additional minutes of preparation
	
	* okay, how about this model:
		* each stack has a number of pancakes, and a divisor, initially 1
		* each additional minute spent serving on the *same* stack will increase it's divisor by 1
		* by this model, we don't have to know the optimal amount of pancakes to move when we first move them
		* naturally we round up when performing the division to calculate stack size
		* the number of pancakes with the current max size is the minimum number of minutes that can be spent serving to improve our situation
		* if we do decide to continue serving, all these max size stacks will have their divisor increased
		* so I think at this point we can employ a greedy strategy:
			loop:
				max_stack_size = the max stack size
				
				candidate_solution = total_serving_time + max_stack_size
				
				if candidate_solution < best_solution:
					best_solution = candidate_solution
				
				if total_serving_time >= best_solution:
					break
				
				pick the largest stack and increment its divisor by 1
				increment total_serving_time by 1
				
				probably we'll keep the stacks in a sorted list, and re-insert the adjusted element in the correct position (maybe binary search) when it moves
		
		* we can't group stacks together by their max size because the divisor may differ, based on the original size of the stacks
		* we potentially have 1M pancakes in the large dataset
		* since we increase a divisor rather than actually tracking stacks individually, our complexity is based on the initial number of diners, D
		* so with the current algorithm, we have potentially 1000 iterations of the outer loop, and potentially 1000 iterations to find the max stack each time, if we don't take special steps - that's O(D*P) or about 1000000 iterations per test case, 100,000,000 total
		* if we need to, we'll use a heap to keep track of the biggest stack
		* probably best if we increment the divisor on all stacks of max size in a single pass, and increment the serving time accordingly

'''

################################################################################

from math import ceil

def read_case(id, input):
	D = int(input.readline())
	stacks = [int(x) for x in input.readline().split()]
	assert D == len(stacks)
	return stacks

class Stack(object):
	def __init__(self, size):
		self.original = size
		self.divisor = 1
		self.size = size

def solve_case(id, case):
	stacks = case
	stacks = [Stack(size) for size in stacks]
	
	biggest_stack = max(stack.size for stack in stacks)
	best_solution = biggest_stack
	serving_time = 0
	
	while True:
		candidate_solution = serving_time + biggest_stack
		if candidate_solution < best_solution:
			best_solution = candidate_solution
		
		# might be able to improve this break condition
		if serving_time >= best_solution: break
		
		# <<< clearly there's room for improvement in picking out the biggest stacks and finding the new biggest stack here, but I think we can scrape through the large dataset as it is
		new_biggest = 0
		for stack in stacks:
			if stack.size == biggest_stack:
				stack.divisor += 1
				serving_time += 1
				stack.size = ceil(stack.original / stack.divisor)
			if stack.size > new_biggest: new_biggest = stack.size
		
		biggest_stack = new_biggest
	
	solution = best_solution
	
	return "Case #{}: {}\n".format(id, solution)


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
	#prepare()
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

