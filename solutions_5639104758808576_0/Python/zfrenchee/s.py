

def rectified(x): return x if x > 0 else 0

def main():

	NumberOfTestCases = int(raw_input())

	for T in range(1, NumberOfTestCases+1): 

		Smax, S = raw_input().split()
		S = map(int, S)

		difference = 0

		for i, s in enumerate(S):

			difference += rectified(i-(sum(S[:i])+difference))

		print 'Case #'+`T`+': '+`difference`



main()
