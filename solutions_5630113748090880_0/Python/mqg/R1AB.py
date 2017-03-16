import sys



t = int(input())

for i in range(t):
	n = int(input())

	board = dict()

	for j in range(2 * n - 1):

		strline = raw_input()

		nums = map(int, strline.split())

		# print(nums)
		for num in nums:
			if board.has_key(num):
				board[num] = board[num] + 1
			else:
				board[num] = 1

	missinglist = list()
	for num in board.keys():
		if board[num] % 2 == 1:
			missinglist.append(num)

	# print(missinglist)
	missinglist.sort()


	strA = 'Case #%d: '%(i+1)
	strB = " ".join(str(x) for x in missinglist)

	printstr = strA + strB
	print(printstr)
