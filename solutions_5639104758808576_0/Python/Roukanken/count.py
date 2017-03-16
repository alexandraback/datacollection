T = int(input())

for case in range(T):
	n, data = input().strip().split()
	data = [int(x) for x in data]

	count = 1
	res = 0
	for i in data:
		if count <= 0: res += 1
		else: count -= 1

		count += i

	print ("Case #{}: {}".format(case+1, res))
