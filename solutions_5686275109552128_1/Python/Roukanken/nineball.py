for case in range(int(input())):
	input()
	data = [int(x) for x in input().strip().split()]

	res = max(data)

	for i in range(2, max(data)+1):
		time = 0
		for a in data: time += (a-1)//i

		res = min (res, time + i)

	print ("Case #{}: {}".format(case+1, res))