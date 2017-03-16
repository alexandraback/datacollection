import math

fi = open("A-large.in")
fo = open("A-large.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	S = str(line.rstrip())
	w = str(S[0])
	for s in S[1:]:
		w = w + str(s) if s < w[0] else str(s) + w

	fo.write("Case #" + str(t+1) + ": " + w + "\n")

fi.close()
fo.close()
