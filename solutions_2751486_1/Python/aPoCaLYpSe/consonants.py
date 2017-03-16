import sys, math

def isVowel(c):
	return c in ["a", "e", "i", "o", "u"]

def solve(name, n):
	substrs = 0
	start = 0
	end = 0
	tot = 0
	#print(name)
	while (start + n <= len(name)):
		while (end < len(name) and tot < n):
			if not isVowel(name[end]):
				tot += 1
			else:
				tot = 0
			end += 1
	#		print(tot, end)
		if (tot == n):
			substrs += 1 + len(name) - end
	#		print(str(start) + " " +  str(end))
		else:
			break
		if end - start == n:
			tot -= 1
		start += 1
	return substrs

infile = open(sys.argv[1],'r')
n = int(infile.readline().strip())
for i in range(n):
	args = infile.readline().strip().split()
	#integer needs to be represented as a list of digits
	n = int(args[1])
	print("Case #" + str(i+1) + ": " + str(solve(args[0], n)))

