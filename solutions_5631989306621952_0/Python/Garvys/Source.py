T = int(input())
for t in range(T):
	s = str(input())
	res = ''
	for c in s:
		if len(res) == 0:
			res = c
		else:
			if ord(c) >= ord(res[0]):
				res = c + res
			else:
				res = res + c
	print("Case #{}: {}".format(t+1,res))