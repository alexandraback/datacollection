import math

def formatLine(line):
	s = line.split()
	s = [int(i) for i in s]

	return s

def solveTestCase(line):
	line = formatLine(line)

def reverse(num):
    return int(str(num)[::-1])


def toNext(x):
	if(x == 1):
		return 10
	if(x == 0):
		return 0
	numzeroes = int(math.ceil((x-2)/2.0))
	numnines = int(math.floor((x-2)/2.0))

	low = int('1' + ('0'*numzeroes) + ('9'*numnines) + '9')
	high = reverse(low)

	print low
	print high

	num = 10**x
	if(x >= 2):
		return num - (high - low) - num/10 + 1



def work(n):
	steps = 0
	l = len(str(n))
	for j in range(l):
		steps += toNext(j)

	a = int(math.ceil(l/2.0))
	b = int(math.floor(l/2.0))

	high = int(str(n)[:a])
	low = int(str(n)[-b:])
	print high
	print low
	print steps

	if n < 21:
		steps = n 
	elif n%10 == 0:
		return work(n-1) + 1
	elif ((reverse(high) + low) < (n - 10**(l-1))):
		steps += reverse(high)
		steps += low
	else:
		print "aaaaa"
		steps += n - 10**(l-1)

	return steps


########
data = open("testfile.txt", 'r')
out = open("answer.txt", "w")
numberCases = int(data.readline())
#########

for i in range(numberCases):

	n = int(data.readline())

	steps = work(n)

	s = "Case #{0:d}: {1:d}\n".format(i+1, steps)
	print s
	out.write(s)