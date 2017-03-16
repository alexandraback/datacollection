# your code goes here

def countPerson(smax, str):
	count = 0
	number = 0
	si = 1
	for i,c in enumerate(str):
		if i < smax:
			number = number + int(c)
			#print i, number, count
			if si > number:
				number = number + 1
				count = count + 1
			si = si + 1
	return count

t = int(raw_input())
for i in xrange(t):
	data = raw_input().split()
	#print data[0], data[1]
	solution = "Case #" + str(i+1) + ": " + str(countPerson(data[0], data[1]))
	print solution