def BinaryArray(num):
	return [int(x) for x in bin(num)[2:]]

def ProcessOne():
	N = raw_input().split()
	A = int(N[0])
	B = int(N[1])
	K = int(N[2])

	summer = 0
	for k in range(A):
		for l in range(B):
			res = k&l
			if res < K:
				summer += 1

	print ("Case #%(id)s: %(opts)s" % {"id" : i+1, "opts" : summer})


	# if A < K or B < K:
	# 	print ("Case #%(id)s: %(opts)s" % {"id" : i+1, "opts" : A * B})
	# 	return

	# for i in range(0, K):
	# 	# Count the number of things that result in this config


T = int(raw_input())

for i in range(T):
	ProcessOne()




