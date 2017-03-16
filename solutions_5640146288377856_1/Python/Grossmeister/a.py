# Task А
import fileinput

def solve(R,C,W):
	moves = 0

	moves += R*(C // W)
	if C % W == 0:
		moves += W - 1
	else:
		moves += W

	return moves

stdin = fileinput.input()
T = int(stdin.readline())
for ti in range(T):
	[R,C,W] = stdin.readline().strip().split(' ')
	print('Case #{0}: {1}'.format(ti+1, solve(int(R),int(C),int(W))))

