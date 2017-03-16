import os, sys, time, math

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		K, L, S = map(int, fin.readline().strip().split())
		Klist = (fin.readline().strip().split())
		target = fin.readline()

		# Sanity Checks:
		answer = S - (L - 1)
		for letter in Klist:
			if letter not in target:
				answer = 0.0
				break
		if answer == 0.0:
			fout.write("Case #%d: %.7f\n" % (t+1, answer))
			print "Case #%d: %.7f" % (t+1, answer)
		else:
			fout.write("Case #%d: %.7f\n" % (t+1, answer))
			print "Case #%d: %.7f" % (t+1, answer)




	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	start = time.time()
	main(fin, fout)
	print time.time() - start