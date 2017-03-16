# coding: utf-8
import sys
import math

if __name__=='__main__':
	T = int(sys.stdin.readline())
	for tc in range(T):
		A,B = [int(it) for it in sys.stdin.readline().split()]
		D = 10**int(math.log10(A))
		#print('A={0} B={1}'.format(A,B))
		
		ans = 0
		for num in range(A,B):
			t = num
			while True:
				t = int(t/10)+(t%10)*D
				if t==num: break
				elif num<t and t<=B: ans += 1
		print('Case #{0}: {1}'.format(tc+1,ans))
