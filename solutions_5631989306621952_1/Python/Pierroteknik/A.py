T = int(input())
for t in range(T):
	print("Case #" + str(t+1) + ": ",end="")
	S = input()
	st = ""
	first = True
	for i in S:
		if first:
			st += i
			first = False
		else:
			if (i>=st[0]):
				st = i + st
			else:
				st = st + i
	print(st)