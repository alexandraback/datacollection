#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2016
Round 1C
Problem C
Fashion Police

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* the total combinations of all 3 items forms an upper limit that is easy to calculate (J * P * S, right?)
	* then... oh... this is not so simple
		* I thought we could just treat JP, PS, JS as 3 independent problems, and pick the minimum... but no
	* J <= P <= S
		* this means that we're going to run into the limit for JP before we ever run into the limit for JS or PS, right?
		* so we look for K times JP, .....
	* we can wear every combination of JP K times, choosing a different S each time....
		* but we would need at least K shirts (S) for this, to ensure unique JPS combo
		* I guess we take the minimum of K and S?
		* after hitting K repeats of all JP combos:
			* we cannot do another repeat of JP without hitting the pair limit (without reusing a combo)
		* after hitting S repeats of JP:
			* we cannot do another repeat without hitting the overall limit
	* there are 3 ways to look at it:
		* all combinations of JP with min(S,K) Shirts
		* all combinations of JS with min(P,K) Pants
		* all combinations of PS with min(J,K) Jackets
	* I think we just find the maximum of these 3 values?
	* we don't even need to consider the overall limit, because these calculations already enforce that?
	* oh, but dammit, that would be too easy.... we also have to actually enumerate them
	* but that's going to be easy enough - we'll just copy/paste the code a bit and have 3 algorithms?
		* error prone, but still maybe the fastest/easiest way in limited time
	* 
	* okay, I coded up that basic solution, just calculating the number of days, to check against the sample dataset
	* turns out I was wrong - my algorithm doesn't account for 2-item combos involving the 3rd item for each of the 3 cases
	* I guess then... maybe we just have to forget the last 2 cases and use the 1st one?
		* because JP is going to be the smallest number... so JPK is the smallest value we'll get based on the 2-item limit
		* I *think* this could be correct, but I'm not certain... but certain enough to code it up and try it
	* damn, I coded it up, but we're failing case 4 of the sample data
		* is our calculation of the number correct though?
	* pants repeat every P outfits
	* jacket repeats every.... outfit? kinda...
	* how about we just keep track of the shirt we had for each pants, and for each jacket, and pick the next one each time.... then cycle around
	
	* looking at the data sizes, it seems size won't be a problem with out J*P*S algorithm
	
	* my solution was relatively straightforward, but still failed.... why?
	* my first guess is that certain outfits are "more expensive" than others, meaning that picking certain outfits may preclude more than a single other outfit from being worn, roughly...
	* can we simple change the nesting order of the main loop to fix this perhaps???
	* inverting the nesting order (putting J on the inside) didn't affect the calculated numbers of outfits
	
	* we know that the final set we end up with cannot have any outfits added, because we considered all outfits and added all that were allowed to be added at the time
	* we know that we don't violate the constraints because we individually check all of them
	* is it possible to remove one outfit and add 2 more, or something like this?
	* or are we making an error in our checking of the constraints?
	* this assertion failed on case 6:
		assert((J * P * min(S, K)) == outfits)
	* not sure of the significance yet...
	* 

'''

################################################################################

from collections import defaultdict

def read_case(id, input):
	case = [int(x) for x in input.readline().split()]
	# assertions would go here if I had more time
	return case

def solve_case(id, case):
	J, P, S, K = case
	
	jp = defaultdict(lambda: 0)
	js = defaultdict(lambda: 0)
	ps = defaultdict(lambda: 0)
	
	outfits = 0
	
	plan = ''
	for j in range(J):
		for p in range(P):
			if (jp[j, p] >= K):
				continue
			ss = sorted(range(S), key=lambda s: max(js[j, s], ps[p, s]))
			for s in ss:
				if (js[j, s] >= K) or (ps[p, s] >= K):
					continue
				
				jp[j, p] += 1
				js[j, s] += 1
				ps[p, s] += 1
				
				outfits += 1
				
				plan += '{} {} {}\n'.format(j+1, p+1, s+1)
	
	#assert((J * P * min(S, K)) == outfits)
	
	#return "Case #{}: {}\n".format(id, outfits)
	return "Case #{}: {}\n{}".format(id, outfits, plan)


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

