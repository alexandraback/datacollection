T = int(raw_input())

def run():
	for case in range(1, T+1):
		K,C,S = map(int, raw_input().split(' '))
		sequence = ' '.join(str(i) for i in range(1,K+1)) 
		if (K == 1):
			print "Case #{}: {}".format(case, 1)
		elif (C >= K):
			a = 2
			for i in range(2,K):
				a = K*(a-1) + i+1
			print "Case #{}: {}".format(case, a)
		else: # C < K
			if (C == 1):
				if (S == K):
					print "Case #{}: {}".format(case, sequence)
				else:
					print "Case #{}: {}".format(case, 'IMPOSSIBLE')
			else: # C > 1
				# determine the initial position
				X = []
				Y = []
				a = 2
				power = K-2
				for i in range(2, C):
					a = K*(a-1) + i + 1
					power -= 1
				X.append(a)
				i = C
				while (power > 0):
					temp = K*i
					if (power >= 2):
						i += 2
					else:
						i += 1
					X.append(temp + i)
					power -= 2	
				for b in Y:
					for j in range(2,C):
						b = K*(b-1) + j + 1
					#X.append(b)	
				if (len(X) > S):
					print "Case #{}: {}".format(case, 'IMPOSSIBLE')
				else:
					print "Case #{}: {}".format(case, ' '.join(str(x) for x in X))
					
run()