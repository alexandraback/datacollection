#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2014
Qualification Round
Problem D
Deceitful War

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* this problem is quite interesting, but I feel that it's not really that hard?
	* seems that Ken's strategy would be to choose the lightest block that is of greater weight than Naomi's, or if there is no such block, his lightest block overall
		* I'm not going to analyse this in any depth - I feel pretty strongly that it's correct
	* then Naomi's strategy for Deceitful War...
		* this is not as simple as Ken's strategy for War
		* obviously she wants to win points, but is it ever possible to make a choice to lose a point now in order to allow gaining more points later?
		* if not, it should be simple to come up with a strategy for her
		* the only way she can win a point is if she has a block that is (genuinely) heavier than all ken's remaining blocks, otherwise he will just pick a heavier one
		* just off the top of my head:
			* naomi keeps picking her lightest block, but reports it as just under the weight of Ken's heaviest, forcing him to get rid of his best blocks for her worst
			* then eventually all her blocks will be heavier and she can start reporting the weights honestly
			* the sudden change from losing completely to winning completely may be a dead giveaway to most people, but I don't think ken has any concept of probability
			* the game of war is so unbalanced though - even with her adjustments, is she still more likely to lose? hmm... maybe I'm wrong about it being unbalanced?
	* oh... turns out we also need to determine naomi's strategy for war...
		* is it possible for her to affect her score by her choice of blocks?
		* I don't think it is
		* I think her "optimal strategy" is to pick randomly?
		* or just from smallest to largest, or any other arbitrary order
		* it doesn't matter which block of naomi's ken gets a point on, since the block he chose (according to his strategy) was equally applicable..... yeah... can't express it right now but I'm convinced enough
		* so, naomi's strategy is simply to pick blocks in order
		* note: we can experimentally test this by randomising or otherwise changing naomi's order and checking how the points change, when applying ken's strategy
		* since her order doesn't affect the score, we choose the order that make it easiest to calculate
	
	* I'm not going to analyse this in depth... I'm just going to go ahead with my proposed strategy
	
	* darn... I'm losing confidence that her order doesn't matter, and furthermore, I'm reluctant to implement an arbitrary order for naomi because I'm convinced the code can be simplified by using a specific order (to make ken's bit easier) or by avoiding "simulation" of the game altogether
	* okay, I wrote some code to calculate the war score which doesn't directly simulate the game, and is O(N)
		* with max 1000 items, and 50 cases, we'd be looking at 50,000,000 iterations, which isn't bad anyway... but I can't help it
	
	* clearly my reasoning about naomi's optimal deceitful war strategy is faulty... the last test case in the sample disagrees with my results, so I'm trying to figure out how she could get 8 out of 9 in that situation...
		* according to that sample case, ken only got 1 point, and naomi got 8
		* the ordering was: NKKNKNKKKNKKNNNKNN
		* okay, if she declares one heavier than any of his, he will pick his lightest - I didn't take advantage of that
		* so as long as she has one heavier than his lightest, she can get a point, only sacrificing her lightest which is heavier than his lightest
		* but now we have the complexity of having to make a decision between sacrificing her lightest for his heaviest, or sacrificing her... just heavier than his lightest, for his lightest
		* oh right, but only one of those two options gets naomi a point - not that that makes it a straightforward decision
		* this might be where the problem gets really tricky - it could even be a dynamic programming problem
		0 NKKNKNKKKNKKNNNKNN
		1 NKKNKKKNKKNNNKNN
		2 NKKKKNKKNNNKNN
		3 NKKKKKNNNKNN
		4 NKKKKNNKNN
		5 NKKKNKNN
		6 NKKKNN
		7 NKKN
		8 NK
		8 
	* so should I just jump to conclusions again that this is the best strategy?
	* this allows her to get a point and eliminate his weakest and her next-weakest
	* does this simply reverse the nature of the game, as if ken and naomi swapped roles in the game of war?... (working out a similar-style algorithm to calculate the points, I noticed the similarity was closer than I would have expected)
		* I think it does
		* I expect I've qualified based on the first 2 questions, so I'll just go ahead with this implementation without convincing myself too hard that it's correct
		* deceitful_war_score(N,naomi,ken) = N - war_score(N, ken, naomi)

'''

################################################################################

def read_case(id, input):
	N = int(input.readline())
	naomi = [float(x) for x in input.readline().split()]
	ken = [float(x) for x in input.readline().split()]
	return N, naomi, ken

def deceitful_war_score(N, naomi, ken):
	return N - war_score(N, ken, naomi)

def war_score(N, naomi, ken):
	
	blocks = [(m, 'n') for m in naomi]
	blocks.extend([(m, 'k') for m in ken])
	blocks.sort()
	
	ncount = 0
	kscore = 0
	nscore = 0
	for m, owner in blocks:
		if owner == 'k':
			if ncount > 0:
				kscore += 1
				ncount -= 1
			else:
				nscore += 1
		elif owner == 'n':
			ncount += 1
	
	if (nscore + kscore) != N:
		raise Exception("({} + {}) != ({})".format(nscore, kscore, N))
	
	return nscore

def solve_case(id, case):
	N, naomi, ken = case
	
	return "Case #{}: {} {}\n".format(id, deceitful_war_score(N, naomi, ken), war_score(N, naomi, ken))


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

