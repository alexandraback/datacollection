# Author: Davin Choo
# Email: cxjdavin@gmail.com

# Approach:
# 1) Go through the list of digits from left to right
# 2) Track how many people are clapping
# 3) Add minimum # of friends to cause next non-zero shyness to clap

T = int(raw_input())

for i in xrange(0, T):
	temp = raw_input().split()
	max_shy = int(temp[0])
	lst = temp[1]

	friends = 0
	clapping = int(lst[0])
	
	for j in xrange(1, max_shy+1):
		if int(lst[j]) != 0:
			if clapping < j:
				diff = j - clapping
				friends += diff
				clapping += diff
			clapping += int(lst[j])

	output = "Case #" + str(i+1) + ": " + str(friends)
	print output