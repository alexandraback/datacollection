def SheepCount(N):
	curState = 0
	curNum = 0
	loopCnt = 0
	while curState != 0x3FF:
		loopCnt += 1
		curNum += N
		temp = curNum
		while temp > 0:
			ldigit = temp % 10
			curState |= 1<<ldigit
			temp //= 10
	return curNum

T = int(input())
for i in range(T):
	N = int(input())
	if N == 0:
		print("Case #"+str(i+1)+": INSOMNIA")
	else:
		print("Case #"+str(i+1)+":",SheepCount(N))