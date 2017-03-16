import io
import math
import time

if __name__ == '__main__' :
	#stime = time.time()
	T = int(raw_input())
	for tt in range(T) :
		N = int(raw_input())
		if N == 0 :
			ans = "INSOMNIA"
		else :
			is_seen = [False for _ in range(10)]
			xx = 1;
			while True :
				num = N * xx
				while num > 0 :
					is_seen[num % 10] = True
					num /= 10
				if sum(is_seen) == 10 :
					# print ii*xx
					break
				else :
					xx += 1
			ans = N*xx
		print ("Case #{}: {}").format(tt+1, ans)
	#print time.time() - stime;
	pass