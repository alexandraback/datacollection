fin = open("d.in", "r")
fout = open("d.out", "w")

t = int(fin.readline())
for casenum in xrange(1, t+1):
	fout.write("Case #" + str(casenum) + ": ")
	(k, c, s) = map(int, fin.readline().split())
	if c*s < k:
		fout.write("IMPOSSIBLE\n")
		continue
	cur = 0
	dig = 0
	for i in xrange(k):
		cur += (k**dig) * i
		dig += 1
		if dig == c or i == k-1:
			fout.write(str(cur+1) + " ")
			dig = 0
			cur = 0
	fout.write("\n")