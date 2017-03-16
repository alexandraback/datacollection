# lines starting with '#' are comments
# to run the code, give input on stdin(that is, standard input, that is, on the terminal simply by typing)
# if your input is in a file, then on linux, you might(should ?) use cat <filename> | python <scriptname>
# eg: cat small-input.txt | python credit.py

import sys, string				# imports modules sys and string. module sys required for reading input; string for doing manipulations on string


if __name__ == '__main__':			# main function starts here; that is what the 'if' check basically means
	refer = dict([('y', 'a'),
		('n', 'b'),
		('f', 'c'),
		('i', 'd'),
		('c', 'e'),
		('w', 'f'),
		('l', 'g'),
		('b', 'h'),
		('k', 'i'),
		('u', 'j'),
		('o', 'k'),
		('m', 'l'),
		('x', 'm'),
		('s', 'n'),
		('e', 'o'),
		('v', 'p'),
		('z', 'q'),
		('p', 'r'),
		('d', 's'),
		('r', 't'),
		('j', 'u'),
		('g', 'v'),
		('t', 'w'),
		('h', 'x'),
		('a', 'y'),
		('q', 'z'),
		(' ', ' ')])
	
	n = int(sys.stdin.readline().split()[0])# reads the first line, that is, the number of cases, n that will need to be checked. 
						# sys.stdin.readline() reads the line, and 'split' splits into words, int() is a typecast function; converts the string to an integer value. so the code is equivalent to writing:
						# line = sys.stdin.readline()
						# list_of_words_in_line = line.split()
						# first_word = list_of_words_in_line[0]
	
	for i in range(n):						# will need to run the loop n times, once for each case. range(n) basically creates an array of n elements, 0 1 2 ... n-1
		G = sys.stdin.readline()
		G = G[0:len(G) - 1]
		string = ''
		for char in G:
			string = string + refer[char]
		print 'Case #{0}:'.format(i+1), string				# print statement; #{n} picks up the nth element in the list of parameters given to format. comma at end means dont move to next line; similar to difference between print and println in java
