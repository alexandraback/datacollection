cases = int(raw_input())


for case in range(cases):
	answer = ""

	K,C,S = [int(i) for i in raw_input().split()]

	# lol S = K

	answer = ' '.join([str(i+1) for i in range(K)])

	print "Case #" + str(case+1) + ": " + answer