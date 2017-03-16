def row_fill(C, W):
	if C % W == 0:
		return C/ W , True
	else:
		return C/ W, False

def count_tries(R, C, W):
	to_hit_one, know = row_fill(C, W)
	to_hit = R * to_hit_one
	if W == 1:
		return to_hit
	else:
		if know:
			return to_hit + W - 1
		else:
			return to_hit + W

def format_ans(num, ans):
	print "Case #" + str(num) + ": " + str(ans)


rounds = int(raw_input())
for i in range(1, rounds + 1):
	line = raw_input()
	R, C, W = map(int, line.split())
	ans = count_tries(R, C, W)
	format_ans(i, ans)