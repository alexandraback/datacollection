#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2014
Qualification Round
Problem B
Cookie Clicker Alpha

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* seems like this could be relatively straightforward
	* farms are the only thing you can spend cookies on
	* clearly if you're going to spend cookies on a farm at all before the end of the game, it's best to do so as early as possible - as soon as you can afford it, so as to maximize the remaining game time in which you receive benefit from the farm
	* don't forget that it's floating point
	* one approach:
		* calculate the time to win with 0 farms, 1 farm, and so on, until the time to buy all the farms (which serves as a minimum win time for future results) is greater than the best time to win so far
		* this will take a number of iterations based on the number of farms - can we avoid that?
		* do we need to avoid that?  what are the problem sizes?
	* can we express the time to win as a function of the number of farms, and then find the minimum with derivatives?
		* I haven't done that kind of math for a long time... but I wouldn't be surprised if the large dataset requires it
	* problem size analysis:
		* cost of a farm cannot be less than 1
		* first farm will take 0.5 seconds minimum
		* next farm will take 0.166666 seconds - 0.666666 seconds total
	* with the best strategy, cookies won't go above the cost of a farm until after the last farm is purchased, so no need to track number of cookies in a variable
	* I'll do this problem the simple way with a loop, and come back later for the large dataset after trying the last 2 problems
	* I'll do a test run with the worst input data (min farm cost, max cookies to win, min farm production) to determine if it can handle it
	* what I believe to be the worst case input - 1 1 100000 - processed in .07 seconds, so 100 of those will process in 7 seconds - no problem & no need to improve algorithm
	

'''

################################################################################


def read_case(id, input):
	C, F, X = [float(x) for x in input.readline().split()]
	return C, F, X

def solve_case(id, case):
	C, F, X = case
	
	time = 0.0
	rate = 2.0
	best = X / rate  # for 0 farms
	
	while time < best:
		interval = C / rate
		time += interval
		rate += F
		wintime = time + X / rate
		if wintime < best:
			best = wintime
	
	return "Case #{}: {}\n".format(id, "%.7f" % best)


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

