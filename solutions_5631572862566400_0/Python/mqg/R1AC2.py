import sys



t = int(input())

for i in range(t):
	n = int(input())

	strline = raw_input()
	nums = map(int, strline.split())

	longest = 0

	for ind in range(n):
		cur = ind + 1

		seat = list()
		seat.append(cur)

		next = nums[cur - 1]
		head = False
		if nums[next - 1] == cur:
			head = True

		while True:
			cur = nums[cur - 1]

			headtail = False
			if (cur == seat[0]):
				headtail = True

			tail = False
			if (cur == seat[len(seat) - 2]):
				tail = True

			if (head or tail or headtail):
				if len(seat) > longest:
					longest = len(seat)

			if tail:
				for ind2 in range(1,n+1):
					if (nums[ind2-1] == seat[len(seat) - 1]) and (ind2 not in seat):
						if len(seat)+1 > longest:
							longest = len(seat)+1

			if head:
				for ind2 in range(1,n+1):
					if (nums[ind2-1] == seat[0]) and (ind2 not in seat):
						if len(seat)+1 > longest:
							longest = len(seat)+1

			if (cur in seat):
				break


			seat.append(cur)


	# print(nums)


	strA = 'Case #%d: '%(i+1)
	strB = str(longest)

	printstr = strA + strB
	print(printstr)
