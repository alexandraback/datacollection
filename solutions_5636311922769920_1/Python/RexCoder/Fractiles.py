import io
import math
import time

if __name__ == '__main__' :
	#stime = time.time()
	T = int(raw_input())
	for tt in range(T) :
		K, C, S = map(int, raw_input().split())
		ans = None
		if C == 1 :
			if S < K :
				ans = 'IMPOSSIBLE'
			else :
				ans = ' '.join(map(str, range(1, K+1)))
			pass
		else :
			if K == 1 :
				ans = 1
			else :
				if S < K - 1 :
					ans = 'IMPOSSIBLE'
				else :
					ans = ' '.join(map(str, range(2, K+1)))
			pass
		print 'Case #{}: {}'.format(tt+1, ans)
	#print time.time() - stime;
	pass