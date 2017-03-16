

N = int(input())
for c in range(N):
	S=input()
	inv=0
	for i in range(len(S)-1):
		if S[i] != S[i+1]:
			inv += 1
	if S[-1] == '-':
		inv += 1
	print("Case #%d: %d" % (c+1, inv))		
