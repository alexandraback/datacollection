T = int(raw_input())

for i in range(T):
	K,C,S = map(int,raw_input().split(" "))
	out = "Case #" + str(i+1) + ":"
	if C*S < K:
		out += " IMPOSSIBLE"
	else:
		for i in range(0,K,C):
			check = 0
			for j in range(0,C):
				check += min(i+j,K-1) * K**j
			out += " " + str(check+1)
	print out