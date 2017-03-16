

for case_no in range(1,int(input().strip())+1):
	K, L, S = list(map(int, input().strip().split(" ")))
	keyboard = list(input().strip())
	kLen = len(keyboard)
	target = input().strip()
	tLen = len(target)

	impossible = False


	for i in range(1, tLen):
		if target[i : tLen] == target[0 : tLen-i]:
			common = tLen-i
			break
	else:
		common = 0

	unique = tLen - common

	SCopy = S
	SCopy = SCopy - common

	N = SCopy // unique

	num = 1
	den = kLen**tLen

	for ch in list(target):
		count = keyboard.count(ch)
		num = num * count
		if count == 0:
			impossible = True


	if impossible:
		ans = 0
	else:
		ans = N * (1 - (num/den))

	x = (num/den)
	if(float(int(x)) == x):
		print("Case #%d: %.1f" % (case_no, ans))
	else:
		print("Case #%d: %.7f" % (case_no, ans))
	
