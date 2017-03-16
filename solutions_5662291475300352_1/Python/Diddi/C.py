import sys

inputpath = sys.argv[1]
outpath = sys.argv[2]

with open(inputpath, "r") as f:
	out = open(outpath, "w")
	T = int(f.readline())
	for case in range(T):
		N = int(f.readline())
		hikers = []
		for _ in range(N):
			D, H, M = map(int, f.readline().split())
			for i in range(H):
				hikers.append([D, M+i])
		crossing = []
		for index, hiker in enumerate(hikers):
			first = hiker[1]*(360-hiker[0])/360
			for i in range(N):
				crossing.append((first+hiker[1]*i,index))
		if N < 2:
			result = 0
		else:
			best = N
			current = N
			crossed = set([])
			sorted_crossing = sorted(crossing)
			index = 0
			while len(crossed) != N:
				start = index
				while index < len(sorted_crossing) and sorted_crossing[start][0] == sorted_crossing[index][0]:
					index += 1
				new = set([y for (x,y) in sorted_crossing[start:index] if y not in crossed])
				not_new = index-start - len(new)
				for x in new:
					crossed.add(x)
				current += - len(new) + not_new
				if current < best:
					best = current
			result = best

		out.write("Case #{}: {}\n".format(case+1, result))
		print("Case #{}: {}".format(case+1, result))
	out.close()
