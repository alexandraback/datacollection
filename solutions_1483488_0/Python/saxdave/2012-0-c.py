#!/usr/bin/python


def rotate(number):
	number = str(number)
	rotations = set()

	for i in range(len(number)):
		number = number[1:] + number[0]
		rotations.add(int(number))

	return rotations


def rotations(number, bound):
	count = 0

	for rotation in rotate(number):
		if number < rotation and rotation <= bound:
			count += 1

	return count


# let's jam!
in_file = open('2012-0-c.in', 'r')
tests = int(in_file.readline())
out_file = open('2012-0-c.out', 'w')

for test in range(1, tests + 1):
	lower, upper = map(int, in_file.readline().strip().split(' '))
	count = 0

	for number in range(lower, upper):
		count += rotations(number, upper)

	output = 'Case #%d: %d\n' % (test, count)
	out_file.write(output)

out_file.close()
in_file.close()
