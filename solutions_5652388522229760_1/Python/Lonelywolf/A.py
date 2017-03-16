import sys

def print_ans(case_num, ans):
	print('Case #%d: %s' % (case_num, ans))

def algorithm(check_set, check_num):
	for s in str(check_num):
		if s in check_set:
			check_set.remove(s)
			if not len(check_set) : return True

	return False

T = int(sys.stdin.readline())
for t in range(T):
	N = int(sys.stdin.readline())

	if N == 0 : print_ans(t+1, 'INSOMNIA')
	else :
		check_set = set(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])
		index = 1;
		while True:
			if algorithm(check_set, N*index) : 
				print_ans(t+1, N*index)
				break;

			index += 1
