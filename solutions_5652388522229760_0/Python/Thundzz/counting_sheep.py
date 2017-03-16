import sys

def digits(number):
	return [int(c) for c in str(number)]

def unique_digits(number):
	return set(digits(number))

def last_number(n):
	current_number = n
	seen_digits = unique_digits(current_number)
	while seen_digits != set(range(10)):
		current_number += n
		seen_digits = seen_digits | unique_digits(current_number)
	return current_number



def main():
	t = int(sys.stdin.readline().strip())
	for i in range(1,t+1):
		n = int(sys.stdin.readline().strip())
		if( n == 0 ):
			print "Case #%d: INSOMNIA" % i
		else:
			print "Case #%d: %d" % (i, last_number(n))



if __name__ == '__main__':
	main()