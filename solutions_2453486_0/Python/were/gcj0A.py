Xwin = ["XXXX", "XXXT", "XXTX", "XTXX", "TXXX"]
Owin = ["OOOO", "OOOT", "OOTO", "OTOO", "TOOO"]

def win(s):
	if s in Xwin:
		return 0
	if s in Owin:
		return 1
	return -1

T = input()

for t in range(T):

	S = []
	for i in range(4):
		S.append(raw_input())
	raw_input()

	ans = -1
	cnt = 0
	s3 = ""
	s4 = ""

	for i in range(4):
		s1 = ""
		s2 = ""
		s3 += S[i][i]
		s4 += S[i][3-i]
		for j in range(4):
			s1 += S[i][j]
			s2 += S[j][i]
			cnt += S[i][j] == 'X' or S[i][j] == 'O' or S[i][j] == 'T'
		if win(s1) != -1:
			ans = win(s1)
			break
		if win(s2) != -1:
			ans = win(s2)
			break

	if win(s3) != -1:
		ans = win(s3)
	if win(s4) != -1:
		ans = win(s4)

	if  ans == -1:
		ans = 2 if cnt == 16 else 3

	print "Case #" + str(t+1) + ": " + ["X won", "O won", "Draw", "Game has not completed"][ans]

