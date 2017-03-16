import os, sys, time, math, itertools

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		C, D, V= map(int, fin.readline().strip().split())
		Dlist = [int(x) for x in fin.readline().strip().split()]

		Value = [0] * (V)
		for i in range(1, len(Dlist)+1):
  			for subset in itertools.combinations(Dlist, i):
				print(sum(subset))
				if sum(subset) - 1 < V:
					Value[sum(subset) - 1] = 1
		print Value
		answer = 0
		while sum(Value) != V:
			# Get all index where V[i] == 1:
			ValidIndx = [-1]
			for i in range(V):
				if Value[i] == 1:
					ValidIndx.append(i)
			print ValidIndx

			# Find smallest index where Value[i] != 0
			indx = 0
			while Value[indx] == 1:
				indx += 1

			print indx

			for i in range(len(ValidIndx)):
				ValidIndx[i] += indx + 1

			print "Post processing: " + str(ValidIndx)
			for i in ValidIndx:
				print i
				if i < V:
					print "Update at index", i
					Value[i] = 1
			print "Post Update:" + str(Value)
			answer += 1
		print Value
		print answer
		fout.write("Case #%d: %d\n" % (t+1, answer))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	start = time.time()
	main(fin, fout)
	print time.time() - start