def solve(inf):
	print(inf)
	return "IMPOSSIBLE"

f = open('C-small-attempt1.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	n = int(f.readline())
	inf = []
	count1 = {}
	count2 = {}
	for ent in range(n):
		x = f.readline().split()
		if x[0] in count1:
			count1[x[0]] += 1
		else:
			count1[x[0]] = 1
		if x[1] in count2:
			count2[x[1]] += 1
		else:
			count2[x[1]] = 1
		inf.append((x[0],x[1]))
	pp = 0
	for p in inf:
		if count1[p[0]] > 1 and count2[p[1]] > 1:
			pp += 1
			count1[p[0]] -= 1
			count2[p[1]] -= 1
	output = 'Case #{0}: '.format(case) + str(pp) + "\n"
	print(output)
	out.write(output)

out.close()