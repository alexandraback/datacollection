#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Round 1C
Problem A
Brattleship

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* seems clear enough that you must try cells a certain width apart on each row
		* that width is W
	* the ship will always be forced to the last position
	* but there will still be possible variance after the first hit (depending on the widths involved)
	* note that he will also play optimally - not greedily
	* after your first hit, he may still be able to force 1 miss, depending on the widths involved
	* the space the ship may be in can be up to 2*W-1 at this point
	* he can only force a maximum of 1 miss, since if you work out from the center, the first miss will give you complete information on the ship location
	* if there is exactly W space, he cannot even force a single miss at this point
	* C - ((per_row - 1) * W) == W
		=> (C / W) - (per_row - 1) == 1
		=> C / W - per_row + 1 = 1
		=> C / W - per_row = 0
		=> C / W = per_row
	* so if C % W != 0, he gets the extra miss
	* score is:
		* per_row = C // W
		* number of tries to get first hit: + R * per_row
		* add remaining hits: + (W - 1)
		* forced miss: + (C % W) ? 1 : 0

'''

################################################################################


def read_case(id, input):
	R, C, W = [int(x) for x in input.readline().split()]
	return (R, C, W)

def solve_case(id, case):
	R, C, W = case
	
	hits = 0
	hits += (C // W) * R
	hits += W - 1
	hits += 1 if (C % W) > 0 else 0
	
	return "Case #{}: {}\n".format(id, hits)


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

