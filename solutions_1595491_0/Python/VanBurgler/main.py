T = int(input())

for t in range(1, T+1):
	result = 0
	g = input().split()

	N = int(g[0])
	S = int(g[1])
	p = int(g[2])
	
	n = [int(g[i]) for i in range(3, N+3)]

	b = 0
	
	for total in n:
		avg = total / 3
		lowest = int(total / 3)
		mid = False
		highest = lowest

		if  lowest * 3 + 2 == total:
			highest = lowest + 1
			mid = True
		elif lowest * 3 + 1 == total:
			highest = lowest + 1

		triplet = [lowest, mid, highest]

		#print(total, triplet)

		if highest  >= p:
			b = b + 1
			continue			

		if S == 0:
			continue

		if highest == lowest and not mid and lowest > 0:
			highest = highest + 1 # 222 -> 123		
		elif highest > lowest and mid:
			highest = highest + 1 # 233 -> 224

		#print("B: ", highest)

		if highest  >= p:
			#print("Surprise")
			b = b + 1
			S = S - 1
			continue	

	print("Case #{}: {}".format(t, b))