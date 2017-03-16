# coding: utf-8
import sys

if __name__=='__main__':
	max0 = [0]*31
	maxS = [0]*31
	for k in range(11):
		for j in range(11):
			for i in range(11):
				diff = max(i,j,k)-min(i,j,k)
				total = i+j+k
				if diff==2:
					maxS[total] = max(maxS[total],i,j,k)
				elif diff==1 or diff==0:
					max0[total] = max(max0[total],i,j,k)
				#print('{0} {1} {2} : {3}'.format(i,j,k,total))
	#print(max0)
	#print(maxS)
	
	T = int(sys.stdin.readline())
	for tc in range(T):
		tokens = sys.stdin.readline().split()
		N = int(tokens[0])
		S = int(tokens[1])
		p = int(tokens[2])
		t = [int(it) for it in tokens[3:]]
		
		#print('{0} {1} {2}'.format(N,S,p))
		#for i in range(N):
		#	print(t[i])
		
		ans = 0
		reach = 0
		for i in range(N):
			if p<=max0[t[i]]:
				ans += 1
			elif p<=maxS[t[i]]:
				reach += 1
		ans += min(S,reach)
		print('Case #{0}: {1}'.format(tc+1,ans))
