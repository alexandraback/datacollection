def solve(k,c,s):
	tiles = []
	
	print(k)
	print(c)
	print(s)
	for i in range(0, -(-k//c)):
		x = 0
		for j in range(0,min(c,k-c*i)):
			x = k*x + (i*c + j)
		tiles.append(x+1)
		
	if len(tiles) <= s:
		return ' '.join(str(i) for i in tiles)
	return "IMPOSSIBLE"

f = open('A-large.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	k,c,s = [int(x) for x in f.readline().split()]
	output = 'Case #{0}: '.format(case) + solve(k,c,s) + "\n"
	print(output)
	out.write(output)

out.close()