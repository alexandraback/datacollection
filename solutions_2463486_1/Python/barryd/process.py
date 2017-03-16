#!/usr/bin/python3

'''

Google Code Jam 2013
Qualification Round
Problem C - Fair and Square

Notes:
	* counting fair & square numbers in an interval
	* it's obvious from the special datasets that there are a few basic strategies we are expected to use, possibly with varying strengths and weaknesses
	* if we can figure out both before doing either problem, we could just add a check on the problem sizes at the outside, and choose the appropriate version of the code based on that
		* this would allow us to have a single program capable of handling all datasets
	* presumably we are to share calculations between cases, in order to get the best result with a large number of cases (large dataset 1)?
		* otherwise they would simply have made the number of cases the same and adjusted the problem size, and that would imply one solution was equal to or better than the other, and negate the need for the additional dataset
	* or maybe they just want to give people the opportunity to solve a large dataset, having only had either insight x or insight y, but if you have both, you can do both with the one program?
	
	* checking a single number for being fair & square is O(1) (if we assume number length in digits is limited), but iterating over the entire range provided and doing that check is still too slow (for the large datasets)
		* okay, checking a 100-digit number for fairness is actually 100 steps, and checking it for square-of-fairness is probably worse, since you're clearly not going to be using platform-native integers
	* but for once, let's do the small dataset first, with the intention to rewrite after solving it
	
	* it will be beneficial to determine the square roots of the range endpoints, and count through those, only checking the squares if the square root was found to be fair already
	* to ensure we still have the range correct, we should either:
		* round up for the lower bound and down for the upper bound, when determining the square-root range
			* this way seems better to me
		* or perform a range check on the resulting squared number, after finding it
	
	* so this simple solution works for the small dataset
	* will it work for the first large dataset?
	* sqrt(10**14) == 10**7 = 10 million
	* 10**7 * 10000 = 10**11 = 100 thousand million
		* that's clearly too large to iterate over
	* also, for the moment I'm just trusting that python will do something useful and reasonably fast with numbers outside the native integer range
		* I think my python is likely 64-bit, so that range would be 2**64 which is about 10**18 (wow, didn't realise it was that big)
		* guess we won't have to worry about non-native integers until we try for the large dataset 2
	* so to avoid that 10**11 iterations, we'll have to share data between cases
	* but... the most obvious method of precalculation won't really help reduce the number of iterations:
		* precalculate whether each number is fair and square or not, for every number in the biggest possible range
		* problem is, we still have to perform the same number of iterations, only we just check the array and increment, instead of performing squaring operations etc.
		* we could break it down somehow, but we don't know where the intervals will begin and end in the range, so how do we know where to break?
		* we could perhaps prepare aggregate values for halves, quarters, etc. of the max range, and somehow sum them to solve each case, but we'd have to store all those values and... well, it's getting complicated now
	* so... if our range is 10**7 (because we work in square roots all the time)...
		* we'll call 10**7 "n" for now
		* to store all the halves etc., would require log(n) arrays
		* the arrays would be size n/2, n/4, etc... up to n/n
		* the overall storage cells required, including the n-item array, would be no greater than 2n (reminds me of my google interview a week ago)
		* to add up the values, you would first add the beginning and end items, if necessary (ie. if the beginning/end was on an odd boundary)
		* then you would switch to the next array (the halves) and do the same for the rounded beginning and end
		* then so on until you hit the final array of a single item, which would only be added if the entire range was covered
		* so you get your sum in log(n) steps
		* which is... about 24 steps?
			* which comes to 24 * 10000 = 240000 iterations overall
		* having to deal with a range that isn't a power of 2 is scaring me... but why not make it a power of 2 by extending the upper limit?
			* perhaps we could even skip calculating the elements we know won't be used?
	* things left to work out:
		* how do we organise the array elements
			* the elements will be stored in a 2n-size array (10**8 elements I guess)
			* we calculate the n individual elements in the outer array first
			* then we add the full size of that array to get the offset of the n/2 elements following
			* and so on
			* for both the calculation and the use of the data, we should be able to proceed from the large array to the smaller arrays
		* is there an easier way that is just as good, which I've ignored because I'm too focused on this direct approach to avoiding 10**7 iterations per case?
	* it's reasonably clear this will work, so I'll go ahead with it and worry about better solutions when I try the large dataset 2
	* thinking of a possibly-simpler way to organise the same rough calculation strategy:
		* perhaps use recursion and memoisation
		* we would have a function like count_range(lower, upper)
		* it would only ever be called with lower/upper bounds that fit into a specific power-of-2 grid
		* another function would be designed to take ranges that don't fit such a grid, and break it down into up to 2 calls that do and 1 call that doesn't necessarily (fit a power-of-2 grid)
		* but I'd rather try the non-recursive way for now
	
	* finer details:
		* we need to cover a range of 10**7 numbers
		* we'll require an array of size 2**(ceil(log(10**7, 2)))
		* multiplied by 2, to accommodate the half-size, quarter-size arrays etc.
		* so that's 2**25

'''

import sys
import time
import math

timeit = 1
debugv = 0

divisions = 24
counts = [0] * (2**(divisions + 1))
def prepare():
	for i in range(2**divisions):
		counts[0 + i] = 1 if fairsquare_inverted(i) else 0
	
	base = 0
	size = 2**divisions
	for i in range(divisions):
		debug("layer {}\n".format(i))
		prev_base = base
		base += size
		size = int(size / 2)
		for j in range(size):
			counts[base + j] = counts[prev_base + (j * 2)] + counts[prev_base + (j * 2) + 1]

def main():
	prepare()
	sys.stderr.write("Completed preparation in {} seconds.\n".format(time.clock() - startTime))
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		doCase(case)

def fair(n):
	digits = str(n)
	for i in range(round(len(digits) / 2)):
		if digits[i] != digits[len(digits)-1-i]:
			return False
	return True

def fairsquare_inverted(n):
	if not fair(n):
		return False
	
	square = n**2
	
	return fair(square)

def doCase(case):
	A, B = [int(n) for n in sys.stdin.readline().split()]
	
	root_A = math.ceil(math.sqrt(A))
	root_B = math.floor(math.sqrt(B))
	
	# now convert to using (start..end-1)-style intervals, because I got really confused doing it the other way
	start = root_A
	end = root_B + 1
	
	result = 0
	
	base = 0
	size = 2**divisions
	# <<< not completely sure about the depth we have to go to, but I'm sure I have at least 1 level in the data that will never be used (because it's outside the largest range) anyway - so this should be good enough
	for i in range(divisions):
		new_start = math.ceil(start / 2)
		new_end = math.floor(end / 2)
		
		if start >= end:
			break
		
		debug("start: {}\nend: {}\nnew_start: {}\nnew_end: {}\n".format(start, end, new_start, new_end))
		
		if (new_start * 2) != start:
			debug("adding {} from {} to {} (level {})\n".format(counts[base + start], start * (2**i), (start + 1) * (2**i) - 1, i))
			result += counts[base + start]
		if (new_end * 2) != end:
			debug("adding {} from {} to {} (level {})\n".format(counts[base + end - 1], (end - 1) * (2**i), (end - 1 + 1) * (2**i) - 1, i))
			result += counts[base + end - 1]
		start = new_start
		end = new_end
		base += size
		size = int(size / 2)
	
	debug("{}\n".format(result))
	sys.stdout.write("Case #{}: {}\n".format(case, result))


def debug(m):
	if debugv:
		sys.stderr.write(m)

if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

