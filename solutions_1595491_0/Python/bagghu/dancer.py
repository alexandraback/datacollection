
import sys, string				# imports modules sys and string. module sys required for reading input; string for doing manipulations on string


if __name__ == '__main__':			# main function starts here; that is what the 'if' check basically means
	
	t = int(sys.stdin.readline().split()[0])# reads the first line, that is, the number of cases, n that will need to be checked. 
						# sys.stdin.readline() reads the line, and 'split' splits into words, int() is a typecast function; converts the string to an integer value. so the code is equivalent to writing:
						# line = sys.stdin.readline()
						# list_of_words_in_line = line.split()
						# first_word = list_of_words_in_line[0]
	
	for i in range(t):						# will need to run the loop n times, once for each case. range(n) basically creates an array of n elements, 0 1 2 ... n-1
		words = sys.stdin.readline().split()
		n = int(words[0])
		s = int(words[1])
		p = int(words[2])
		T = []
		for j in range(n):
			T.append(int(words[3+j]))
		T.sort(None, None, True)
		maxi = 0
		for num in T:
			if(num < p):
				break
			avg = num / 3
			if avg >= p:
				maxi += 1
			elif avg == p-1:
				if(3*avg + 1 == num or 3*avg + 2 == num):
					maxi += 1
				else:
					if(s > 0):
						maxi += 1
						s -= 1
					else:
						break
			elif avg == p-2:
				if(3*avg + 2 == num and s > 0):
					maxi += 1
					s -= 1
				else:
					break
			else: 
				break

		print 'Case #{0}:'.format(i+1), maxi				# print statement; #{n} picks up the nth element in the list of parameters given to format. comma at end means dont move to next line; similar to difference between print and println in java
