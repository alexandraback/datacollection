filename = "AL"
fin = open (filename+'.in', 'r')
fout = open (filename+'.out', 'w')

_N = int(fin.readline().strip())
for _i in range(_N):
	R, C, W = [int(a) for a in fin.readline().strip().split(' ')]
	count = 0
	print(R, C, W)

	count = R * (C // W)
	#count += W - 1
	m = C % W
	count += m + (0 if m == 0 else 1)
	count = count + W - m - 1
	#count = count + (C % W)

	fout.write('Case #'+str(_i+1)+': '+str(count)+'\n')
	print('Case #'+str(_i+1)+': '+str(count)+'\n', end="")