import math

T = input()
T = int(T)

for a in range(1,T+1):

	raw = input()
	raw2 = raw.split(" ")
	K = raw2[0]
	C = raw2[1]
	S = raw2[2]
	K = int(K)
	C = int(C)
	S = int(S)

	if(K > C*S):
		result = "Case #" + str(a) + ": IMPOSSIBLE"
	else:
		result = "Case #" + str(a) + ":"
		P = K // C
		Q = K % C

		for i in range(P):
			piece = 0
			for j in range(C):
				piece += (C*i + j)*(K**j)
			piece += 1
			result += " " + str(piece)

		if Q > 0:
			piece = 0
			for z in range(Q):
				piece += (C*P + z)*(K**z)
			piece += 1
			result += " " + str(piece)

	print(result)
