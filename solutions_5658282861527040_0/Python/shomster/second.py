from collections import defaultdict

lines = open('B-small-attempt0.in', 'r').read().splitlines()
line = iter(lines)

numCases = int(line.next())

outputFile = open('B-small-attempt0.out', 'w')

for i in range(numCases):
	# print "****"
	(A, B, K) = map(lambda t: int(t), line.next().strip().split())
	# print (A, B, K)

	cnt = 0
	for a in range(A):
		for b in range(B):
			if a & b < K:
				cnt = cnt + 1



	# binary_a = bin(a - 1)[2:]
	# binary_b = bin(b - 1)[2:]
	# len_binary_a = len(binary_a)
	# len_binary_b = len(binary_b)

	# for k in range(K):
	# 	binary_k = bin(k)[2:]
	# 	len_binary_k = len(binary_k)
	# 	a = A / 
	
	outputFile.write("Case #" + str(i + 1) + ": " + str(cnt) + "\n")



