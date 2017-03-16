import math, sys

def main():
	file_read = open(sys.argv[1], 'r')
	lines = file_read.readlines()	
	no_test_cases = int(lines[0])
	l = 0 ; 
	for k in range(no_test_cases):	
		print "Case #" + str(k+1) + ": "
		
		sums = {} ; result = [] ; result = -1
		x = lines[k+1]
		x = x.split()
		x = x[1:]
		for j in range(len(x)):
			x[j] = int(x[j])
		f = lambda x: [[y for j, y in enumerate(set(x)) if (i >> j) & 1] for i in range(2**len(set(x)))]
		subsets = f(x)
		for k in range(len(subsets)):			
			if sum(subsets[k]) in sums.keys():
				sums[sum(subsets[k])].append(subsets[k])
				result = sum(subsets[k])
				break
			else:
				sums[sum(subsets[k])] = []
				sums[sum(subsets[k])].append(subsets[k])

		for k in range(len(sums[result])):	
			for j in range(len(sums[result][k])):	
				print sums[result][k][j],
			print ""
		
if __name__ == '__main__':
	main()