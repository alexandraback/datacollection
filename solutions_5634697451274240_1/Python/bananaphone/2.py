T = int(raw_input())

def doprob():
	read = raw_input()
	start = read[0]
	current = start
	length = 1
	for i in read:
		if i == current:
			continue
		current = i
		length += 1
	if current == '+':
		length -= 1
#	if length == 0:
#		return 0
	return length

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())