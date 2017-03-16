n = int(raw_input())
for case in range(1, n + 1):
	answer = 0
#	if A + 1 <= K or B + 1 <= K:
#		answer = A * B
#		print "Case #%d: %d" % (case, answer)
#		continue
	A, B, K  = map(int, raw_input().split(' '))
	for i in range(A):
		if i < K:
			answer += B
		else:
			for b in range(B):
#				print (i & b), K
				if i & b < K:
					answer += 1

	print "Case #%d: %d" % (case, answer)
