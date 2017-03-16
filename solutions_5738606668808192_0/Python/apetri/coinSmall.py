#!/usr/bin/env python
import sys
from operator import add
from functools import reduce
from itertools import combinations

import numpy as np

evaluate_jam = lambda s,b: reduce(add,([int(c)*(b**(len(s)-n-1)) for n,c in enumerate(s)]))

#Generate a JamCoin (a^N+1)(a^n1 + a^n2 + ... + 1)
def generateJam(N,K,k):

	#Safety check
	assert (k<K).all()
	assert k[-1]==0

	#Compute JamCoin representation
	powers = np.concatenate((k+K,k))
	jamcoin_string = ["0"]*N
	for p in powers:
		jamcoin_string[p] = "1"
	jamcoin_string = "".join(jamcoin_string)

	#Compute the divisors
	divisors = []
	for b in range(2,11):
		divisors.append(b**K+1)

	#Return
	return jamcoin_string,divisors

#Generate random draws for jamcoin generation
def drawk(K,ndraws=50):
	choose_from = range(1,K)
	combos = []
	for n in range(1,len(choose_from)+1):
		combos += combinations(choose_from,n) 
		if len(combos)>=ndraws:
			return combos[:ndraws]


#####################
#########Main########
#####################

line = lambda : sys.stdin.readline().strip("\n")

def main():

	#Number of test cases
	ntest = int(line())
	assert ntest==1

	#Cycle over test cases
	for t in range(ntest):

		#Read in N,J
		N,J = [int(c) for c in line().split(" ")]

		#Write preamble
		sys.stdout.write("Case #{0}:\n".format(t+1))

		#Generate J draws for the JamCoins
		k_draws = drawk(7,J)
		for k in k_draws:
			coin,divisors = generateJam(N,N-7-1,np.array((7,)+k+(0,)))
			sys.stdout.write(coin + " " + " ".join([ str(d) for d in divisors ]) + "\n")

if __name__=="__main__":
	main()