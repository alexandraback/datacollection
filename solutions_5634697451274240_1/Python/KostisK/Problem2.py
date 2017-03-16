import itertools

def le_flip(num):
	return (num + 1)% 2

# Exclysive
def flip(array, ind):
	array = map(le_flip, list(reversed(array[0:ind]))) + array[ind:]
	return array

def numberize(num):
	if(num == '-'):
		return 0
	else:
		return 1


fd = open("in2", "r")

lines = fd.readlines()

testcases = int(lines[0])



fout = open("out2", "w")

for line_ind in xrange(1,len(lines)):
	line  = lines[line_ind]
	moves = 0

	fout.write("Case #" + str(line_ind) + ": ")

	pancakes = map(numberize, line[:-1])


	bottom = 0
	for i in xrange(0,len(pancakes)):
		if(pancakes[-i-1] == 0):
			bottom = len(pancakes) - i
			break

	while bottom > 0:
		if(pancakes[0] == 1):
			for i in xrange(1,len(pancakes)):
				if(pancakes[i] == 0):
					pancakes = flip(pancakes, i)
					moves += 1
					break	
		else:
			pancakes = flip(pancakes, bottom)
			bottom = 0
			moves += 1
			for i in xrange(0,len(pancakes)):
				if(pancakes[-i-1] == 0):
					bottom = len(pancakes) - i
					break
	fout.write(str(moves) + "\n")
