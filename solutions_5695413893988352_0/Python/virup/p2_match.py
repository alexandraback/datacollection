import sys
import time

#assumes: c and j have the same length
#tie-breaker: minimize final a. second-level-tie-breaker: minimize final b
def closest_match(a,b):
	out_a, out_b = '', ''
	pass
	return out_a + ' ' + out_b


def brute_force(a,b):
	if '?' not in a and '?' not in b:
		return (a,b,abs(int(a)-int(b)))
	for i in range(len(a)):
		if a[i] == '?':
			min_diff = 10**18
			min_a, min_b = None, None
			for d in range(10):
				if i == len(a)-1:
					new_a = a[:i]+str(d)
				else:
					new_a = a[:i]+str(d)+a[i+1:]
				(x,y,diff) = brute_force(new_a,b)
				if diff < min_diff:
					min_diff = diff
					min_a, min_b = x, y
			return (min_a, min_b, min_diff)
	for j in range(len(b)):
		if b[j] == '?':
			min_diff = 10**18
			min_a, min_b = None, None
			for d in range(10):
				if j == len(b)-1:
					new_b = b[:j]+str(d)
				else:
					new_b = b[:j]+str(d)+b[j+1:]
				(x,y,diff) = brute_force(a,new_b)
				if diff < min_diff:
					min_diff = diff
					min_a, min_b = x, y
			return (min_a, min_b, min_diff)


def main():
	start_time = time.time()
	input_file = sys.argv[1]
	with open(input_file, 'r') as f:
		lines = f.readlines()

	for i in range(1,len(lines)):
		c,j = lines[i].split()
		(a,b,diff) = brute_force(c,j)
		print "Case #%d: " % i + a + ' ' + b
	
	# print "Time (seconds):", time.time()-start_time

if __name__ == "__main__":
	main()
