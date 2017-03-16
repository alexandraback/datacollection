
import sys, string				# imports modules sys and string. module sys required for reading input; string for doing manipulations on string


if __name__ == '__main__':			# main function starts here; that is what the 'if' check basically means
	
	t = int(sys.stdin.readline().split()[0])# reads the first line, that is, the number of cases, n that will need to be checked. 
						# sys.stdin.readline() reads the line, and 'split' splits into words, int() is a typecast function; converts the string to an integer value. so the code is equivalent to writing:
						# line = sys.stdin.readline()
						# list_of_words_in_line = line.split()
						# first_word = list_of_words_in_line[0]
	
	for i in range(t):						# will need to run the loop n times, once for each case. range(n) basically creates an array of n elements, 0 1 2 ... n-1
		words = sys.stdin.readline().split()
		a = words[0]
		b = words[1]
		int_a = int(a)
		int_b = int(b)
		count = 0
		for num in range(int_a, int_b):
			n = str(num)
			m = n
			n_digit = len(n)
			L = []
			for k in range(0, n_digit - 1):
				tmp = m[n_digit - 1]
				m = tmp + m[:-1]
				int_m = int(m)
				if(num < int_m and int_m <= int_b):
					if m in L:
						pass
					else:
						L.append(m)
						count += 1
		print 'Case #{0}:'.format(i+1), count				# print statement; #{n} picks up the nth element in the list of parameters given to format. comma at end means dont move to next line; similar to difference between print and println in java
