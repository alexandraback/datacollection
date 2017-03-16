import sys
T = 0
Smax = 0
case_num = 0
for line in sys.stdin:
	if T == 0:
		T = int(line.split('\n')[0])
	else:
		S=[]
		[cnt, sum] = [0, 0]
		Smax = int(line.split('\n')[0].split(' ')[0])
		S= ' '.join(line.split('\n')[0].split(' ')[1]).split(' ')
		sum += int(S[0])
		for i in range(1, len(S)):
			if sum < i and int(S[i])>0:
				cnt += i-sum
				sum += i-sum
			sum += int(S[i])
		case_num += 1
		print "Case #{0}: {1}".format(str(case_num), str(cnt))