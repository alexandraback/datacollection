from itertools import product

X = {
	'1': {'1': '1', 'i': 'i',  'j': 'j',  'k': 'k' ,   '-1': '-1', '-i': '-i', '-j': '-j', '-k': '-k'},
	'i': {'1': 'i', 'i': '-1', 'j': 'k',  'k': '-j',   '-1': '-i', '-i': '1', '-j': '-k', '-k': 'j'},
	'j': {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i',    '-1': '-j', '-i': 'k', '-j': '1', '-k': '-i'},
	'k': {'1': 'k', 'i': 'j',  'j': '-i', 'k': '-1',   '-1': '-k', '-i': '-j', '-j': 'i', '-k': '1'},
	
	'-1': {'1': '-1', 'i': '-i', 'j': '-j',  'k': '-k',   '-1': '1', '-i': 'i', '-j': 'j', '-k': 'k'},
	'-i': {'1': '-i', 'i': '1',  'j': '-k',  'k': 'j',    '-1': 'i', '-i': '-1', '-j': 'k', '-k': '-j'},
	'-j': {'1': '-j', 'i': 'k',  'j': '1',  'k': '-i',    '-1': 'j', '-i': '-k', '-j': '-1', '-k': 'i'},
	'-k': {'1': '-k', 'i': '-j', 'j': 'i',  'k': '1',     '-1': 'k', '-i': 'j', '-j': '-i', '-k': '-1'}
}


def main():

	NumberOfTestCases = int(raw_input())

	for T in range(1, NumberOfTestCases+1):

		numchars, repeats = map(int, raw_input().split())
		pattern = list(raw_input())

		print 'Case #'+`T`+': '+canItBeDone(pattern, repeats)


def canItBeDone(pattern, exponent):

	if len(set(pattern)) < 2: return 'NO'

	# if some I and some K exist, and they have space between them, and the entire sequence evaluate to -1, 
	# then the space between them must be j, and we return yes. 
	if evaluateString(pattern, exponent) == ['-1']:

		if exponent < 5: 

			allPossibleI = allSubsetsWhichStartAtTheBeginning( pattern * exponent )
			allPossibleK = allSubsetsWhichEndAtTheEnd( pattern * exponent )

			firstI = allPossibleI.index('i') if 'i' in allPossibleI else float("inf")
			lastK = allPossibleK[::-1].index('k') if 'k' in allPossibleK else float("inf")

			if firstI + lastK < len(pattern) * exponent: return 'YES'

		else:

			# if all patterns cycle for every 4th power, then you don't need to compute anything else than 
			span = sum([evaluateString(pattern, i) for i in [0,1,2,3,4]], []) # this is the worst hack in the history of hacks

			# we need to get an i from the cross of span and allSubsetsWhichStartAtTheBeginning + []
			# we need to get a k from the cross of allSubsetsWhichEndAtTheEnd + [] and span 
			# we need to keep track of the middle as well.

			BeginningSubsets = allSubsetsWhichStartAtTheBeginning(pattern)
			EndingSubsets = allSubsetsWhichEndAtTheEnd(pattern)

			allPossibleI = map(evaluatePattern, product(span, BeginningSubsets))
			allPossibleK = map(evaluatePattern, product(EndingSubsets, span)) 

			firstI = allPossibleI.index(['i']) if ['i'] in allPossibleI else float("inf")
			lastK = allPossibleK[::-1].index(['k']) if ['k'] in allPossibleK else float("inf")

			if firstI + lastK < len(pattern) * exponent: return 'YES'


	return 'NO'


def doesStringEvaluateTo(char, pattern, exponent):
	return char == evaluateString(pattern, exponent)

def evaluateString(pattern, exponent):

	if exponent == 0: return ['1']

	if exponent == 1: return evaluatePattern(pattern)

	if exponent % 2 == 0: return evaluateString(evaluatePattern(pattern+pattern), exponent/2)

	return evaluatePattern(pattern+evaluateString(pattern, exponent-1))


def evaluatePattern(S): 

	return [reduce(lambda accumulator, next: X[accumulator][next] , S, '1')]

def allSubsetsWhichStartAtTheBeginning(S): return reduce(lambda accumulator, next: accumulator + [X[accumulator[-1]][next]] , S, ['1'])

def allSubsetsWhichEndAtTheEnd(S): return allSubsetsWhichStartAtTheBeginning(S[::-1])[::-1]

main()


