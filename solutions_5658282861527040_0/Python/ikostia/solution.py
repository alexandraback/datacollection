#! /usr/bin/python

debug = False

def solve(input_data):
	A, B, K = input_data
	res = 0
	for a in xrange(A):
		for b in xrange(B):
			if a & b < K:
				res += 1

	return str(res)

def read_input():
	A, B, K = map(int, raw_input().split())
	return (A, B, K)
	
def main():
	T = int(raw_input())
	for t in xrange(T):
		print "Case #%d: %s" % (t + 1, solve(read_input()))

if __name__ == "__main__":
	main()
