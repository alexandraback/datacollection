import math
import sys
import linecache

# function to check palindromes
def palindrome_checker(number):
	
	str_num = str(number)
	str_reverse_num = ''
	for char in str_num:
		str_reverse_num = char + str_reverse_num
	
	if str_num == str_reverse_num:
		return True
	else:
		return False

		
list = []

for i in range(0, 10000000):
	if palindrome_checker(i):
		list.append(i*i)

list_2 = []

for item in list:
	if palindrome_checker(item) == True:
		list_2.append(item)

# put file into memory
# it's a small file, so f*ck you if you don't like it
# Put file into memory
linecache.getline(sys.argv[1], 1)

for i in range(0, int(linecache.getline(sys.argv[1], 1))):
	
	line = linecache.getline(sys.argv[1], i + 2)
	
	interval_list = [int(x) for x in line.split()]
	small = interval_list[0]
	large = interval_list[1]
	counter = 0
	for fairnsquare in list_2:
			
		if fairnsquare >= small and fairnsquare <= large:
				
			counter += 1

	print "Case #%d: %d" % (i+1, counter)
				