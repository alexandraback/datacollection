def solve(str):
	noswitches = 0
	lastchar = 'x'
	for s in str:
		if s != lastchar:
			noswitches += 1
		lastchar = s
	
	if lastchar == '-':
		return noswitches
	else:
		return noswitches-1

f = open('A-small.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	s = f.readline().strip()
	output = 'Case #{0}: {1}'.format(case, solve(s)) + "\n"
	print(output)
	out.write(output)

out.close()