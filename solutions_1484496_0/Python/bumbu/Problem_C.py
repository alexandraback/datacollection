import string
import itertools

def imposible(numbers, half):
	for x in range(1,len(numbers)):
		combinations_x = itertools.combinations(numbers, x)
		for x_x in combinations_x:
			# x first combination
			if(sum(x_x)>half):
				break
			numbers_cut = set(numbers).difference(set(x_x))
			# print set(numbers).difference(set(x_x))
			for y in range(1,len(numbers_cut)):
				combinations_y = itertools.combinations(numbers_cut, y)
				for y_y in combinations_y:
					if sum(x_x) == sum(y_y):
						return "\n" + " ".join(["%s" % el for el in list(x_x)]) + "\n" + " ".join(["%s" % el for el in list(y_y)])
						# return " ".join(list(x_x))
						# .split y_y
	return "Imposible"



_file = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_C/C-small-attempt0.in")
# _file = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_C/data.txt")
lines = int(_file.readline())
_result = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_C/result.txt", "w")

line = _file.readline()
i = 1
while(line != ""):
	line = line.replace("\n", "")

	numbers_string = line.split(" ")[1:]
	numbers = []
	for n in numbers_string:
		numbers.append(int(n))
	
	_sum = sum(numbers)
	half = _sum/2

	result = imposible(numbers, half)


	if i > 1:
		_result.write("\n")
	_result.write("Case #" + str(i) + ": " + result)
	line = _file.readline()
	i += 1
	

_file.close()
_result.close()