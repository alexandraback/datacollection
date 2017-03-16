def solve(b,m):
	m -= 1
	x = "{0:b}".format(m)
	print (x)
	if(len(x) > b-2 and x != '0'):
		return [False, 0]
	else:
		r = [[c for c in x.zfill(b-1)+'1']]
		for p in range(b-1):
			r.append([0] * (p+2) + [1] * (b-2-p))
		return [True, r]

f = open('B-large.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	b,m = [int(x) for x in f.readline().split()]
	poss,res = solve(b,m)
	if(poss):
		output = 'Case #{0}: '.format(case) + "POSSIBLE" + "\n" + '\n'.join([''.join([str(y) for y in x]) for x in res]) + "\n"
	else:
		output = 'Case #{0}: '.format(case) + "IMPOSSIBLE" + "\n"
	print(output)
	out.write(output)

out.close()