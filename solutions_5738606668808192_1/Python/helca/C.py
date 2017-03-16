def subsets(k):
	S = []
	if k == 1:
		return ['00', '11']
	for s in subsets(k-1):
		S.append('00' + s)
		S.append('11' + s)
	return S

print 'Case #1:'

S = subsets(9)
for i in range(500):
	print '11' + S[i] + '000000000011' + ' 3 4 5 6 7 8 9 10 11'