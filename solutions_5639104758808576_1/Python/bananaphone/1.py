T = int(raw_input())

def doprob():
	read = raw_input()
	read = read.split()
	n = int(read[0])
	nums = list(read[1])
	cums = [None]
	for i in xrange(len(nums)):
		if i == 0:
			cums.append(int(nums[i]))
		else:
			cums.append(cums[i] + int(nums[i]))
#	print nums, cums, [i - cums[i] for i in xrange(1, n+1)]
#	if n >= 1:
	tmp = max(i - cums[i] for i in xrange(1, n+2))
#	else:
#		tmp = 0
	return max((tmp, 0))

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())