import os, sys, time, math

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		R, C, W = map(int, fin.readline().strip().split())
		print "Starting case #%d" % (t+1)
		if C % W == 0:
			answer = (C/W + (W - 1)) * R
		else:
			answer = (C/W + (W - 1) + 1) * R
		print "Case #%d: %d" % (t+1, answer)
		fout.write("Case #%d: %d\n" % (t+1, answer))
	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	start = time.time()
	main(fin, fout)
	print time.time() - start