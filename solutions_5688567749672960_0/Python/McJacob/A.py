import sys

results = {1 : 1}

def main(input_file):
	number_of_cases = int(input_file.readline().strip("\n"))
	for case_number in xrange(1, number_of_cases + 1):
		print "Case #%d: %d" % (case_number, case(input_file, case_number))

def reverse_number(n):
	reversed = 0
	while n > 0:
		reversed *= 10
		reversed += n % 10
		n /= 10
	return reversed
		

def get_result(n):
	if n in results:
		return results[n]
	if n % 10 == 0:
		result = get_result(n - 1) + 1
		results[n] = result
		return result
	reversed = reverse_number(n)
	if reversed >= n:
		result = get_result(n - 1) + 1
		results[n] = result
		return result
	result = min(get_result(n - 1), get_result(reversed)) + 1
	results[n] = result
	return result
		
def case(input_file, case_number):
	n = int(input_file.readline().strip("\n"))
	
	for i in xrange(1, n):
		get_result(i)
	
	return get_result(n)
	
if __name__ == '__main__':
	main(open(sys.argv[1]))


