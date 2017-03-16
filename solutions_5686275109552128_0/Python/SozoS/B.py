# Author: Davin Choo
# Email: cxjdavin@gmail.com

# Observations:
# Doing all the splits before eating cannot make the solution worse
# Always splitting to an empty plate cannot make the solution worse
# So, we always split first, and split to empty plate
# (Exploit fact that we have infinite customers)

# Approach: Brute force search
# Set a maximum height to allow customers to eat at
# Eat for the lowest stack height given that constraint

T = int(raw_input())

for i in xrange(0, T):
	D = int(raw_input())
	temp = raw_input().split()

	sizes = {}
	largest = 0
	for j in xrange(0, D):
		pj = int(temp[j])
		largest = max(largest, pj)

		if pj not in sizes:
			sizes[pj] = 0
		sizes[pj] += 1

	# Sort pancake stack height in descending order
	descending = sorted(sizes, reverse = True)

	# Brute force check all possibilities
	best_time = largest
	best_height = largest
	for h in xrange(largest-1, 1, -1):
		current_time = 0

		# Split
		for d in descending:
			if d <= h:
				break
			else: # d > h
				if d % h == 0:
					current_time += sizes[d] * (d/h-1)
				else:
					current_time += sizes[d] * d/h
		
		# Eat
		current_time += h
		
		# Update
		if current_time < best_time:
			best_time = current_time
			best_height = h

	# print best_height
	print "Case #" + str(i+1) + ": " + str(best_time)