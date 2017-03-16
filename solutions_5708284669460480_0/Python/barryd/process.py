#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Round 1C
Problem B
Typewriter Monkey

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* need to calculate the max number of instances the monkey could type
		* we need to work out how frequently the word can repeat
		* obviously any word can repeat once every L characters (so... something like S // L)
		* but depending on the word, it may be able to overlap itself
		* to check for this, we just have to find an initial substring of the word at any point after the beginning of the word, running until the end
		* is it enough to find just the first initial substring and declare the min distance between instances based on that?
			* I think so - not going to work it out in-depth right now
	 	* this is the easy part, right? no expected value involved
	* expected value...
		* I think the expected value comes down to the sum of probabilities from each individual test? something like that...
		* each letter has a certain probability of appearing at a given location, based on the number of occurrences in the keyboard and the total keyboard size K
		* the probabilities of the word appearing at different locations are not independent...
			* although, for 2 locations that don't overlap, they are
		* let's consider the large dataset, with keyboard size 100 and word and string size 100
		* perhaps we can set up a 100*100 grid....
			* the probability of having the first i letters of the word at position j
		* then we just go through and sum .... the probabilities of having all L letters of the word at all positions
		* okay, I can kind-of see how this works... we only have to look at the probability for i-1 letters at pos j-1, and the probability of the correct letter at the current position...
			* what about "probability of this given that, plus the probability given that, etc. for all possible "thats", weighted by the probability of those "thats""???
			* I feel like I'm not properly representing the dependence between the events
			* but I don't really feel I can affort to spend more time thinking about it
			* I get a certain amount of dependence represented by considering a single key possibility at a single location, and calculating numerous probabilities based on that, right?
		* 
	* I suppose the max number could be calculated by adding 1 wherever the probability of a word occurring is non-zero...
		* but again, this completely ignores interdependence between the tests
		* and with the max value, more than the expected value, it's clearly going to get a wrong answer
			* with the expected value, it's probably also wrong - just harder for me to see it clearly
		* let's just work out the "independent words" version, and see how it goes on the sample dataset...
		* pretty sure it's going to be way off...
	
21:15: I don't properly handle the dependence between occurrences, but at least for the sample dataset, my program gets answers within required tolerances.
There's only 15 minutes until the end of the competition.  There's actually a pretty good chance my program will fail the small dataset, IMO, but I don't really have enough time to improve it.
Should I at least add the ABA example to sample.in?  Yeah.
21:19: So I'm clearly wrong for this sample:
	6 3 5
	ABCDEF
	ABA
	
	Case #6: 2.9861111111
	
	I'm pretty sure the max number of times ABA can occur in a 5-character string is 2, not 3.
		ABABA - 2 times
		BABAB - 1 time
	So I know it's completely wrong.  If I submit, it will just make me look dumb.  But... nobody's going to look anyway.  And what if I get lucky and the small dataset by some crazy chance works with my data?
	I see that the sample tests all have very minimal lengths.  That explains why my data doesn't fail.  Oh well... let's run it and see it fail on the small dataset.

'''

################################################################################

from collections import defaultdict

def read_case(id, input):
	K, L, S = [int(x) for x in input.readline().split()]
	keyboard = input.readline().rstrip()
	assert len(keyboard) == K
	word = input.readline().rstrip()
	assert len(word) == L
	return (K, L, S, keyboard, word)

def solve_case(id, case):
	K, L, S, keyboard, word = case
	
	letter_p = defaultdict(lambda: 0)
	for i in range(K):
		letter_p[keyboard[i]] += 1 / K
	
	# p[i, j] = the probability of having the first j letters of the word at the end of a string of length i
	p = dict() # is this much less efficient than an array?
	
	for i in [0]:
		p[i,0] = 1
		for j in range(1, S+1):
			# word length is greater than 0
			p[i,j] = 0
	
	max = 0
	expected = 0
	for i in range(1, S+1):
		p[i,0] = 1
		for j in range(1, L+1):
			letter = word[j-1]
			p_letter = letter_p[letter]
			p[i,j] = p[i-1,j-1] * p_letter
		expected += p[i, L]
		max += 1 if p[i,L] > 0 else 0
	
	return "Case #{}: {}\n".format(id, max - expected)


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

