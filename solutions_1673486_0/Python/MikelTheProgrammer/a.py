def prod(iterable):
	result = 1
	for x in iterable:
		result *= x
	return result

def expected1(num_typed, num_total, prob):
	prob = prod(prob)
	return (num_total - num_typed + 1) * prob + (1.0 - prob) * (num_total + 1 + num_total - num_typed  + 1)

def expected2(num_typed, num_total, prob):
	result = []
	for j in xrange(1, num_total - num_typed + 1):
		total = 0
		p = prod(prob[:num_typed - j]) #* prod(1.0 - x for x in prob[num_typed - j:])
		total += p * (2 * j + 1 + num_total - num_typed)
		total += (1.0 - p) * (2 * j + 1 + num_total - num_typed + num_total + 1)
		result.append(total)
	return result

def expected3(num_typed, num_total, prob):
	return 1 + num_total + 1

def best_expected(num_typed, num_total, prob):
	#print expected1(num_typed, num_total, prob)
	#print expected2(num_typed, num_total, prob)
	#print expected3(num_typed, num_total, prob)
	return min(min(expected2(num_typed, num_total, prob)), 
		expected1(num_typed, num_total, prob), 
		expected3(num_typed, num_total, prob))

def main():
	T = int(raw_input()) # num test cases
	for case in xrange(1, T + 1):
		a, b = tuple([int(d) for d in raw_input().split()])
		p = [float(d) for d in raw_input().split()]
		
		print "Case #%d: %f" % (case, best_expected(a, b, p))

if __name__ == "__main__":
	main()

