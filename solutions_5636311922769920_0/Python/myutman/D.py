from math import *

t = int(input())
for j in range(1, t + 1):
	print("Case #" + str(j) + ": ", end="")
	k, c, s = map(int, input().split())
	ans = (k + c - 1) // c
	if (ans > s):
		print("IMPOSSIBLE")
		continue
	i = 0
	while (i < k):
		ot = 0
		for z in range(min(k - i, c)):
			ot *= k
			ot += i + z
		ot += 1
		print(ot, end = " ") 
		i += c
	print()

#... ... ...