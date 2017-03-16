
T = int(raw_input())
for i in xrange(1,T+1):
	K, C, S = [int(value) for value in raw_input().split(" ")]
	if C*S < K:
		print "Case #{}: {}".format(i, "IMPOSSIBLE")
	else:
		positions = []
		for j in xrange(S):
			position = 0
			if C*j >= K:
				break
			for k in xrange(C*j, C*(j+1)):
				value = k
				if value >= K:
					value = K-1
				position = K*position + value
			positions.append(position+1)

		to_print = ''
		for number in positions:
			to_print += str(number) + ' '

		print "Case #{}: {}".format(i, to_print)