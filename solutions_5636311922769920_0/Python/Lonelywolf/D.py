import sys

def print_ans(case_num, ans):
	print('Case #%d: %s' % (case_num, ans))

T = int(sys.stdin.readline())
for t in range(1, T+1):
	K, C, S  = [int(x) for x in sys.stdin.readline().split()]
	min_s = int((K-1)/C + 1)
	if S<min_s : print_ans(t, 'IMPOSSIBLE')
	else :
		ans = []
		scope = list(range(K))

		loop = K
		if K > C : 
			loop = C
			if K % C != 0:
				for i in range(C - (K % C)) :
					scope.append(0)

		scope.reverse()
		
		while len(scope) > 0 :
			idx = 0
			for i in range(loop):
				idx *= K
				idx += scope.pop()
			ans.append(str(idx+1))

		print_ans(t, ' '.join(ans))