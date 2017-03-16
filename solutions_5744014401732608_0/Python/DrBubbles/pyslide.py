import sys

T = int(sys.stdin.readline())
for C in range(T):

	B, M = [int(x) for x in sys.stdin.readline().split()]
	if M > 2 ** (B-2):
		print("Case #" + str(C+1) + ": IMPOSSIBLE")
		continue
	else:
		print("Case #" + str(C+1) + ": POSSIBLE")
		if M is 2**(B-2):
			print("0"+"1"*(B-1))
		else:
			print("{0:b}".format(2*M).zfill(B))
		for x in range(B-2):
			print("0"*(x+2)+"1"*(B-x-2))
		print("0"*B)

