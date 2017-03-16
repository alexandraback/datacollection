#!/usr/bin/python


MIN_SCORE = 0
MAX_SCORE = 10


def scorable(total, best):
	remainder = total % 3
	value = total / 3

	if remainder == 0:
		normal = MIN_SCORE <= value \
		and value <= MAX_SCORE \
		and value >= best

		surprise = MIN_SCORE + 1 <= value \
		and value <= MAX_SCORE - 1 \
		and value + 1 >= best 

	elif remainder == 1:
		normal = MIN_SCORE <= value \
		and value <= MAX_SCORE - 1 \
		and value + 1 >= best

		surprise = MIN_SCORE + 1 <= value \
		and value <= MAX_SCORE - 1 \
		and value + 1 >= best

	elif remainder == 2:
		normal = MIN_SCORE <= value \
		and value <= MAX_SCORE - 1 \
		and value + 1 >= best

		surprise = MIN_SCORE <= value \
		and value <= MAX_SCORE - 2 \
		and value + 2 >= best

	return (normal, surprise)


# let's jam!
in_file = open('2012-0-b.in', 'r')
tests = int(in_file.readline())
out_file = open('2012-0-b.out', 'w')

for test in range(1, tests + 1):
	data = map(int, in_file.readline().strip().split(' '))
	number, surprises, best = data[0:3]
	total = data[-number:]

	certain = 0
	need_surprise = 0
	can_surprise = 0

	for i in range(number):
		normal, surprise = scorable(total[i], best)
		can_surprise += int(surprise)

		if normal:
			certain += 1

		else:
			need_surprise += int(surprise)

#	if can_surprise >= surprises:
#		output = 'Case #%d: %s\n' % (test, certain + min(need_surprise, surprises))

#	else:
#		output = 'Case #%d: 0\n' % test
#		print 'Case #%d: too many surprises' % test
#		print surprises, can_surprise

	output = 'Case #%d: %s\n' % (test, certain + min(need_surprise, surprises))
	out_file.write(output)

out_file.close()
in_file.close()
