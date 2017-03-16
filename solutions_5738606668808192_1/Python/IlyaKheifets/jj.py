import sys

pw = [1] * 11
nm = [0] * 11
cnt = 0

print("Case #1:")
for i in range((1 << 31) + 1, 1 << 32, 2):
	if cnt == 500:
		break
	for j in range(2, 11):
		pw[j] = 1
		nm[j] = 0
	for k in range(32):
		for j in range(2, 11):
			if (i & (1 << k)) > 0:
				nm[j] += pw[j]
			pw[j] *= j
	res=[]
	for k in range(2, 11):
		t = True
		for j in range(2, 2016):
			if nm[k] % j == 0:
				res.append(j)
				t = False
				break
		if t:
			break
	if len(res) == 9:
		cnt += 1
		print("{0:b}".format(i), end = ' ')
		for r in range(len(res)):
			if r > 0:
				print(end = ' ')
			print(res[r], end = '')
		print()
