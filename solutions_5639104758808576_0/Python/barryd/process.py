#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Qualification Round
Problem A
Standing Ovation

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:

	* there is no advantage to giving an invited friend a shyness level other than 0
	* we need at least 1 member with shyness 0 or less, 2 with shyness 1 or less, 3 with shyness 2 or less, up to n with shyness n-1 or less
	* so it makes sense to sort them, then count through
	* at each element, the required shyness increases by 1
	* if at any point we don't have the required shyness, we add a friend (which could have shyness anywhere from 0 to the current requirement - it doesn't affect the remainder of the calculation) and continue to just add 1 each element as we have been doing
	
	* so we have a loop - on each iteration we:
		* increase the number of people standing to the shyness level of the current member
		* add friends for the amount by which we increased the number of people standing (minimum 0 friends)
		* increase the number of people standing by 1
		* proceed to the next entry in the array
	
	* the above loop has 1 iteration per original audience member
	* but it assumes an array of a shyness level for each audience member... which isn't what we're getting
	* so our objective is to achieve the required maximum shyness level in people standing
	* our loop:
		* add enough friends to bring standing to the current shyness level (minimum 0)
		* increment standing by the current entry value
		* move to the next entry
	
	* note that we don't have to check for non-zero value at a particular point, because we'll eventually get a non-zero at the end, and any audience members up to and including that one will require the friend/s we add at this stage

'''

################################################################################


def read_case(id, input):
	line  = input.readline().split()
	Smax = int(line[0])
	audience = [int(x) for x in line[1]]
	
	assert audience[-1] > 0
	assert len(audience) == Smax + 1
	
	# the problem statement doesn't name the input array
	# I decided to call it audience for now
	
	return audience

def solve_case(id, case):
	audience = case
	
	standing = 0
	friends = 0
	for required_standing, new_audience in enumerate(audience):
		if standing < required_standing:
			new_friends = required_standing - standing
			standing += new_friends
			friends += new_friends
		
		assert standing >= required_standing
		standing += new_audience
	
	solution = friends
	
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

