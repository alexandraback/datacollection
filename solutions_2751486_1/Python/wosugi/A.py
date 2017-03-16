# -*- coding: utf-8 -*-
import sys

def has_empty(board):
	for j in range(N):
		for i in range(N):
			if board[j][i]=='.':
				return True
	return False

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		tokens = sys.stdin.readline().split()
		name = tokens[0]
		n = int(tokens[1])
		name = name.translate(name.maketrans('aeiou','_____'))
	#	print('{} {}'.format(name,n),file=sys.stderr)
		
		L = len(name)
		consec = [0]*L
		consec[0] = 1 if name[0]!='_' else 0
		for p in range(1,L):
			consec[p] = consec[p-1]+1 if name[p]!='_' else 0
	#	print(consec,file=sys.stderr)
		
		buf = [0]*L
		buf[0] = 0 if consec[0]<n else 1
		ans = buf[0] #n-value
		for p in range(1,L):
		#	print('{}: {}'.format(p,consec[p]),file=sys.stderr)
			buf[p] = buf[p-1] if consec[p]<n else (p-n)+2
		#	print('{}'.format(buf),file=sys.stderr)
			ans += buf[p]
	#	print(buf,file=sys.stderr)
		
		print('Case #{}: {}'.format(t+1,ans))
		print('Case #{}: {}'.format(t+1,ans),file=sys.stderr)
