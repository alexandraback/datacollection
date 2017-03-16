import math

casesLen = int(input())

cases = []

for case in range(casesLen):
	a,b,k = [int(x) for x in input().split(' ')]
	k = k-1
	ret = 0
	for i in range(a):
		for j in range(b):
			if i & j <= k:
				ret = ret + 1
	print("Case #{}: {}".format(case+1,ret))
