def solve(k,c,s):
	if s >= k:
		tiles = range(1,k+1)
		return ' '.join(str(i) for i in tiles)
	return "Illegal!"
	return "IMPOSSIBLE"

f = open('A-small.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	k,c,s = [int(x) for x in f.readline().split()]
	output = 'Case #{0}: '.format(case) + solve(k,c,s) + "\n"
	print(output)
	out.write(output)

out.close()