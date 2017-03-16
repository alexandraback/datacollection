import sys

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		line = fin.readline().split()
		Smax = int(line[0])
		S_list = [int(x) for x in list(line[1])]
		print S_list
		new = 0
		accum = 0
		for i in range(len(S_list)):
			print "Iteration %d" % (i)
			print "%d vs %d \n" % (S_list[i] + new + accum, i)
			if (S_list[i] + new + accum) < (i+1):
				new += (i+1) - (S_list[i] + accum + new)
			accum += S_list[i]

		fout.write("Case #%d: %d\n" % (t+1, new))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	main(fin, fout)
