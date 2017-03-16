# -*- coding: utf-8 -*-
import sys

def is_possible(board,N,M):
	highestN = [-1]*N
	highestM = [-1]*M
	for n in range(N):
		for m in range(M):
			highestN[n] = max(highestN[n],board[n][m])
			highestM[m] = max(highestM[m],board[n][m])
	
	for n in range(N):
		for m in range(M):
			model = min(highestN[n],highestM[m])
			if board[n][m]!=model:
				return False
	return True

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		N,M = [int(i) for i in sys.stdin.readline().split()]
		board=[]
		for i in range(N):
			board.append([int(i) for i in sys.stdin.readline().split()])
	#	print(board,file=sys.stderr)
		
		ans = 'YES' if is_possible(board,N,M) else 'NO'
		print('Case #{}: {}'.format(t+1,ans))
		print('Case #{}: {}'.format(t+1,ans),file=sys.stderr)
