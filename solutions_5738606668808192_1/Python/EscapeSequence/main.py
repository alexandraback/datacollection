def solve(n, j):
	ans = []
	for r in range(0, 2 << (n-4)):
		r += 2 << (n-3)
		k = [int(d) for d in str(bin(r))[2:]]
		if sum(k[0::2]) - sum(k[1::2]) != 1:
			continue
		else:
			k.append(1)
		
		m = int(''.join(str(i) for i in k) )
		ans.append([m, 3,4,5,6,7,8,9,10,11])
		#for b in range(2,10+1):
			#if int(str(m),b) % (b+1) != 0: print("Oops: {}".format(m))
		if len(ans) == j: return ans
	return ["Ouch"]

f = open('A-large.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	n, j = [int(x) for x in f.readline().split()]
	output = 'Case #{0}:\n'.format(case)
	for l in solve(n, j):
		output += ' '.join(str(i) for i in l) + "\n"
	print(output)
	out.write(output)
