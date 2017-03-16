import urllib, urllib2, cookielib
import re #biblioteca que procura expressao regular
import os #roda o programa em C que trata a entrada gerada
import string
import itertools

from sys import argv
from utils import *

reader = InputReader("input.txt", input_lines=1)
output_list = []

def tentativa(S, N):
	for i in range(2, N):
		for j in range(1, N-i):
			first = itertools.combinations(S, i)
			second = itertools.combinations(S, j)
			for x in first:
				for y in second:
					if (x == y):
						continue
					else:
						somax = 0
						for xd in x:
							somax += xd
						somay = 0
						for xd in y:
							somay += xd
						if somax == somay:
							strin = "\n"
							for xd in x:
								strin += str(xd) + ' '
							strin = strin[:-1] + '\n'
							for xd in y:
								strin += str(xd) + ' '
							return strin[:-1]
	return "Impossible"


# number of tests
for i in reader.lines:
	# for each test
	numbers = string.split(i, ' ')
	count = 0
	N = int(numbers[0])
	# for each contestant
	#print "N" + str(N)

	S = []
	for i in range(1, N + 1):
		S.append(int(numbers[i]))
	S.sort()
	result = tentativa(S, N)
	
	print result
	output_list.append(result)
OutputWriter("output.txt", output_list)
