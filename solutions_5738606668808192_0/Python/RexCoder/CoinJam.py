import io
import math
import time

def b10tobx(dec, x) :
	ans = 0
	ii = 0
	while dec > 0 :
		ans += (dec % x)*(10**ii)
		dec /= x
		ii += 1
	return ans

def b2tobx(bin, x) :
	ans = 0
	ii = 0
	while bin > 0 :
		ans += (bin % 10) * (x**ii)
		bin /= 10
		ii += 1
	return ans
	
def find_factor(x) :
	for ii in range(2, int(math.sqrt(x)+1)) :
		if x % ii == 0 :
			return ii
	return -1

if __name__ == '__main__' :
	#stime = time.time()
	T = int(raw_input())
	N, J = map(int, raw_input().split())
	
	curr = 2**(N-1)+1 # 1...0N...1
	print "Case #1: "
	while J > 0 :
		arr = []
		is_valid = True
		for bb in range(2, 11) :
			curr_bb = b2tobx(b10tobx(curr, 2), bb)
			curr_bb_factor = find_factor(curr_bb)
			if curr_bb_factor == -1 :
				is_valid = False
				break
			else :
				arr.append(curr_bb_factor)
		if is_valid :
			print "{} {}".format(b10tobx(curr, 2), ' '.join(map(str, arr)))
			J -= 1
		curr += 2
		pass
	#print time.time() - stime;
	pass