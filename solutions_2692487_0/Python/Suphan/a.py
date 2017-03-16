import sys

if len(sys.argv) < 3:
	print 'input/output file name must be defined.'
	exit(1)

input_file = open(sys.argv[1])
output_file = open(sys.argv[2], 'w')
num = int(input_file.readline())
for i in range(num):
	line1 = input_file.readline().split()
	A = int(line1[0])
	N = int(line1[1])
	M = sorted(map(int, input_file.readline().split()))
	ans = []
	if A > 1:
		ops = 0
		count = 0
		for m in M:
			if m < A:
				A += m
			else:
				ans.append(ops + (N - count))
				while m >= A:
					A += (A - 1)
					ops += 1
				A += m
			count += 1
		ans.append(ops)
	else:
		ans.append(N)
	#print ans
	selected = min(ans)
	output_file.write('Case #' + str(i + 1) + ': ' + str(selected) + '\n')

input_file.close()
output_file.close()