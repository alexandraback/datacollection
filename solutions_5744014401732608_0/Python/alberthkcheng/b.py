t = int(raw_input())

def get_solution(b, m):
	if m > 2**(b-2):
		return [False, None]
	elif m == 2 ** (b-2):
		answer = list()
		temp = ["1"] * b
		for i in range(b):
			temp[i] = "0"
			answer.append("".join(temp))
		return [True, answer]
	else:
		answer = list()
		# to binary
		temp = "{0:b}".format(m) + "0"
		answer.append(temp.zfill(b))
		temp = ["1"] * b
		temp[0] = "0"
		for i in range(1, b):
			temp[i] = "0"
			answer.append("".join(temp))
		return [True, answer]


for i in range(t):
	[b, m] = map(int, raw_input().split(" "))
	[is_possible, answer] = get_solution(b,m)
	if is_possible == True:
		print "Case #" + str(i+1) + ": " + "POSSIBLE"
		for row in answer:
			print row
	else:
		print "Case #" + str(i+1) + ": " + "IMPOSSIBLE"
