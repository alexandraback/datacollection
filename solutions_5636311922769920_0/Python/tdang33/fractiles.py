T = int(raw_input())

for case in range(1, T+1):
	K,C,S = map(int, raw_input().split(' '))
	sequence = ' '.join(str(i) for i in range(1,K+1)) 
	print "Case #{}: {}".format(case, sequence)