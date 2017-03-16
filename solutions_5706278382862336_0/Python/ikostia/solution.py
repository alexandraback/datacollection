#! /usr/bin/python

debug = False

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def solve(input_data):
	den, num = input_data
	d = gcd(den, num)
	den = den / d
	num = num / d

	bnum = map(lambda d: d == '1', list(bin(num)[3:]))
	if any(bnum):
		return "impossible"

	res = 1
	while den < num / 2:
		res += 1
		den = den * 2

	return str(res)

def read_input():
	s = raw_input()
	den, num = map(int, s.split("/"))
	return (den, num)
	
def main():
	T = int(raw_input())
	for t in xrange(T):
		print "Case #%d: %s" % (t + 1, solve(read_input()))

if __name__ == "__main__":
	main()
