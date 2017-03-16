from itertools import permutations
from heapq import heappush, heappop
from sets import Set
N = int(raw_input())
         
for T in range(N):
	[J, P, S, K] = map(int, raw_input().strip().split())

	mins = sorted([J, P, S])
	kDay = mins[0] * mins[1] * K
	jDay = J * P * S
	dDay = min(kDay, jDay)
	print "Case #%d: %d" % (T+1, dDay)

	while dDay > 0:
		seen = Set()
		for x in range(1, J+1):
			if dDay == 0:
				break
			for y in range(1, P+1):
				if dDay == 0:
					break
				for z in range(1, S+1):
					if dDay == 0:
						break
					could = " ".join(map(str, [x, y, z]))
					seen.add(" ".join(map(str, ["O", y, z])))
					seen.add(" ".join(map(str, [x, "O", z])))
					seen.add(" ".join(map(str, [x, y, "O"])))
					if could not in seen:
						dDay -= 1
						print could
						seen.add(could)


