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
			crossing.append((first,index))
			crossing.append((first+hiker[1],index))
		if N < 2:
			result = 0
		else:
			first, second = sorted(crossing)[:2]
			if first[1] == second[1]:
				result = 1
			else:
				result = 0
			print(first,second)


		out.write("Case #{}: {}\n".format(case+1, result))
		print("Case #{}: {}".format(case+1, result))
	out.close()
