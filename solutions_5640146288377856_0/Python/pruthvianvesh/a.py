for case_no in range(1,int(input().strip())+1):
	R, C, W = list(map(int, input().strip().split(" ")))
	if (C%W) == 0:
		extra = 0
	else:
		extra = 1
	ans = ((C // W) * R) + (W - 1) + extra
	print("Case #%d: %d" % (case_no, ans))