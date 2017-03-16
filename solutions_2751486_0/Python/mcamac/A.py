T = input()

vowels = 'aeiou'

def good(st, n):
	run = 0
	bestrun = 0
	for c in st:
		if c in vowels:
			bestrun = max(run, bestrun)
			run = 0 
		else:
			run += 1
	bestrun = max(run, bestrun)
	# print st, bestrun, n
	return (bestrun >= n)

for case in range(1, T+1):
	line = raw_input().strip().split()
	[s, n] = line
	n = int(n)

	# runs = []

	
	# for c in s:
	# 	if c in vowels:

	tot = 0
			
	for i in range(len(s)):
		for j in range(i, len(s)+1):
			sb = s[i:j]
			# print sb
			if good(sb, n):
				tot += 1

	print "Case #%d: %d" % (case, tot)