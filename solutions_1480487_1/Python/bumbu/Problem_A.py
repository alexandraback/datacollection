import copy
import string
from decimal import *
getcontext().prec = 6
# _file = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_A/data.txt")
# _file = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_A/A-small-attempt11.in")
_file = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_A/A-large.in")
lines = int(_file.readline())
_result = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1B/Problem_A/result.txt", "w")

line = _file.readline()
i = 1
while(line != ""):
	line = line.replace("\n", "")

	points = line.split(" ")[1:]
	users = len(points)

	points_min = copy.copy(points)

	_sum = 0.0
	for p in points:
		_sum += int(p)

	_sumx2 = _sum*2
	_min = _sumx2/users
	# print _min
	for p in points:
		if int(p) >= _min:
			points_min.pop(points_min.index(p))
			_sumx2 -= int(p)

	users = len(points_min)
	_min2 = _sumx2/users
	print _min2

	result = ""
	for p in points:
		p = int(p)
		if(p >= _min):
			result += "0.0 "
		else:
			result += str(round(max(0.0,(_min2-p)/(_sum))*100, 6)) + " "
	# print _sum

	if i > 1:
		_result.write("\n")
	_result.write("Case #" + str(i) + ": " + result[:-1])
	line = _file.readline()
	i += 1
	

_file.close()
_result.close()