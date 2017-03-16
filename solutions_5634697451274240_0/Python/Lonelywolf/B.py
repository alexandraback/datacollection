import sys

def print_ans(case_num, ans):
	print('Case #%d: %s' % (case_num, ans))

def algorithm(S):	
	cnt = 0
	cur = S[0]
	for s in S :
		if cur != s :
			cur = s
			cnt += 1

	if cur == '-' : return cnt+1
	else : return cnt
	

T = int(sys.stdin.readline())
for t in range(T):
	S = str(sys.stdin.readline())
	print_ans(t+1, algorithm(S[:len(S)-1]))