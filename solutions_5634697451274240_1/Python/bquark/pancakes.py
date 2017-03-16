fi = open("B-large.in")
fo = open("B-large.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	S = [1 if s=='+' else 0 for s in line.rstrip()]
	count = 0
	for i in range(len(S)-1):
		if S[i+1] != S[i]:
			count += 1
	if S[-1] == 0:
		count += 1

	fo.write("Case #" + str(t+1) + ": " + str(count) + "\n")

fi.close()
fo.close()
