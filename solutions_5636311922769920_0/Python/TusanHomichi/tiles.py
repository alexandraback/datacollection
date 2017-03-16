T = int(raw_input())

for i in range(T):
	K,C,S = map(int,raw_input().split(" "))
	out = "Case #" + str(i+1) + ":"
	for i in range(K):
		out += " " + str(1 + i*K**(C-1))
	print out