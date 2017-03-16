calcReturn = 0

def init():
	cnt[0][0] = cnt0[0][0] = 1
	cnt[1][1] = cnt[1][4] = cnt[1][9] = 1
	cnt0[1][0] = cnt0[1][1] = cnt0[1][4] = cnt0[1][9] = 1
	cnt[2][2] = cnt[2][8] = 1
	cnt0[2][0] = cnt0[2][2] = cnt0[2][8] = 1
	for length in range(3, 120):
		cnt0[length] = [x for x in cnt0[length - 2]]
		cnt0[length][0] = 1
		for digitsum in range(1, 10):
			for i in range(1, 3):
				j = digitsum - i * i * 2
				if j >= 0:
					cnt[length][digitsum] += cnt0[length - 2][j]
					cnt0[length][digitsum] += cnt0[length - 2][j]

def DFS(depth, digitSumSquare, length, lst, result):
	global calcReturn
	if (length + 1) / 2 == depth:
		if int(''.join(map(str, result))) <= int(''.join(map(str, lst))):
			calcReturn += 1
		return 
	digitPut = 2
	if (length & 1) and length / 2 == depth:
		digitPut = 1
	startDigit = 0
	if not depth:
		startDigit = 1
	for digit in range(startDigit, lst[depth]):
		digitSumSquare2 = digitSumSquare + digit * digit * digitPut
		if digitSumSquare2 > 9:
			break
		calcReturn += sum(cnt0[length - depth * 2 - digitPut][0 : 10 - digitSumSquare2])
	digit = lst[depth]
	digitSumSquare2 = digitSumSquare + digit * digit * digitPut
	result[depth] = result[length - depth - 1] = digit
	if digitSumSquare2 <= 9:
		DFS(depth + 1, digitSumSquare2, length, lst, result)

def calc(x):
	if not x:
		return 0
	global calcReturn
	l = len(str(x))
	calcReturn = sum(cnt[length][digitsum] for length in range(1, l) for digitsum in range(1, 10))
	DFS(0, 0, l, map(int, list(str(x))), [0] * l)
	return calcReturn
	
cnt = [[0] * 10 for _ in range(120)]
cnt0 = [[0] * 10 for _ in range(120)]
init()
taskNumber = input()
for taskIdx in range(1, taskNumber + 1):
	A, B = map(int, raw_input().split())
	lower, upper = 1, B
	while lower <= upper:
		medium = (lower + upper) / 2
		if medium ** 2 <= B:
			b = medium
			lower = medium + 1
		else:
			upper = medium - 1
	lower, upper = 1, A
	while lower <= upper:
		medium = (lower + upper) / 2
		if A <= medium ** 2:
			a = medium
			upper = medium - 1
		else:
			lower = medium + 1
	print ('Case #%d: ' % taskIdx) + str(calc(b) - calc(a - 1))
