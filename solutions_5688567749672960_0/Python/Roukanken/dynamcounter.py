actions = [lambda x: x+1, lambda x: int("".join(reversed(str(x))))]

for case in range(int(input())):
	N = int(input())
	data = [0, 1] + [9999999999 for i in range(N)]


	for i in range(1, N):
		for action in actions:
			next = action(i)

			if len(data) > next:
				data[next] = min(data[next], data[i]+1)


	print ("Case #{}: {}".format(case+1, data[N]))
