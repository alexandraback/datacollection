fin = open('C-small-attempt0.in', 'r')
fout = open('C-small-attempt0.out','w')


def vertstorepeat(bffs,i):
	hits = [False]*N
	
	j = i
	curlen = 0
	while not(hits[j]):
		hits[j] = True
		j = bffs[j]
		curlen = curlen + 1
	
	return (curlen,j)

numtests = int(fin.readline().rstrip())

for test in range(numtests):
	N = int(fin.readline().rstrip())
	bffs = [int(b)-1 for b in str(fin.readline().rstrip()).split(" ")]
	
	bffpairchainlens = {i:0 for i in range(N) if bffs[bffs[i]] == i}
	result = 0
	
	# case 1: a bff cycle
	for i in range(N):
		hits = [False]*N
		
		j = i
		curlen = 0
		while not(hits[j]):
			hits[j] = True
			j = bffs[j]
			curlen = curlen + 1
		
		if bffs[bffs[j]] == j:
			bffpairchainlens[j] = max(curlen-2,bffpairchainlens[j])
		else:
			if j == i:
				result = max(result,curlen)
	
	# case 2: a sequence of bff chains
	# for i in bffpairchainlens:
	# 	if bffpairchainlens[i] < bffpairchainlens[bffs[i]]:
	# 		bffpairchainlens[i] = 0
	
	result = max(result, sum([bffpairchainlens[i] for i in bffpairchainlens]) + len(bffpairchainlens.keys()))
	
	outstr = "Case #" + str(test+1) + ": " + str(result) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)


