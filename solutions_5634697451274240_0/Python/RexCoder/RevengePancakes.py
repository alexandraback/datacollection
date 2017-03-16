import io
import math
import time

if __name__ == '__main__' :
	#stime = time.time()
	T = int(raw_input())
	for tt in range(T) :
		pcakes = list(reversed(raw_input()))
		pcakes = [1 if x == '-' else 0 for x in pcakes]
		flip = 0
		acc = 0
		for ii in range(len(pcakes)) :
			if (pcakes[ii]+acc) % 2 == 0 :
				continue;
			else :
				flip += 1
				acc += 1
			pass
		print "Case #{}: {}".format(tt+1, flip)
	#print time.time() - stime;
	pass