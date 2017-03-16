import math
import itertools

def makes_string(word, num_chars):
	overlap = 0
	i = 0
	while i < len(word):
		if word[i:] == word[:(-1*i)]:
			overlap = len(word) - i
			i = len(word)
		else:
			i+=1
	head = word[:overlap]
	tail = word[overlap:]
	result = head + tail * num_chars
	result = result [:num_chars]
	return result

def counts_occurrences(string, word):
	len_word = len(word)
	times = 0
	i = 0
	while i <= len(word):
		if string[i:len(word) + i] == word:
			times += 1
			i+=1
		else:
			i+= 1
	return times

def makes_strings(keys):
	return itertools.permutations(keys)


def max_occurrences(word, num_chars):
	overlap = 0
	i = 0
	while i < len(word):
		if word[i:] == word[:(-1*i)]:
			overlap = len(word) - i
			i = len(word)
		else:
			i+=1
	#print("overlap is", overlap)
	return 1 + ((num_chars // (len(word) - overlap)) - len(word))


def prob(target, keys):
	prob = 1
	for letter in target:
		change = keys.count(letter) / len(keys)
		prob *= change
	return prob

# def possible_occurrences(str_len, targ):
# 	if str_len < len(word):
# 		return 0
# 	elif str_len == len(word):
# 		return 1
# 	else:
# 		overlap_chars = 0
# 		counter = 0
# 		back_counter = -1
# 		still_possible = true
# 		while still_possible = true:
# 			if word[counter] == word[back_counter]:
# 				overlap_chars += 1
# 				counter +=1

# 			else:
# 				still_possible = false

def solve(str_len, target, keys):
	if str_len < len(target):
		return 0
	elif target.count(target[0]) == len(target) and keys.count(keys[0]) == len(keys):
		return 0
	else:
		total = 0
		for stringz in makes_strings(keys):
			word_prob = prob(stringz, keys) * counts_occurrences(stringz, target)
			total += abs(word_prob)


		return total


		
def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1
len_file = file_len('sexy_text.txt')


getdata = open('sexy_text.txt')
getdata.readline().strip()


def make_list():
	long_list = []
	for i in range(len_file -1):
		line = getdata.readline().strip()
		line = line.split(" ")
		if len(line) > 1:
			newline = getdata.readline().strip()
			otherline = getdata.readline().strip()
			result_line = [int(line[2]), otherline, newline]
			long_list.append(result_line)
	return long_list
long_list = make_list()

for i in range(len(long_list)):
 	line = solve(long_list[i][0], long_list[i][1], long_list[i][2])
 	print("Case #{0}: {1}".format(i+1, line))