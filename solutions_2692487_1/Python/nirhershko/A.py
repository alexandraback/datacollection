	
def get_operations(A,sizes):
	if A<2:
		#we cant make A bigger..
		return len(sizes)
	
	enlargements_needed = [0]
	enlargements = 0
	for size in sizes:
		while A<=size:
			A += A-1
			enlargements += 1
		
		enlargements_needed.append(enlargements)
		
		A += size
	
	removals_needed = range(len(sizes),-1,-1)
	operations_needed = map(sum, zip(removals_needed,enlargements_needed))
	return min(operations_needed)
	

def read_numbers(count=None):
	line = raw_input()
	tokens = [tok.strip() for tok in line.split(" ")]
	
	if count!=None:
		assert len(tokens) == count
	
	return map(int, tokens)

def main():
	T = read_numbers(1)[0]
	for i in range(T):
		A,N = read_numbers(2)
		sizes = read_numbers(N)
		sizes.sort()
		num = get_operations(A,sizes)
		print "Case #%d: %d" % (i+1,num)

main()
