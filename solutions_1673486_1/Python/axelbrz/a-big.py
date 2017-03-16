exName = "a-big"

# str to str
def solve(line1, line2):
	A, B = int(line1.split(" ")[0]), int(line1.split(" ")[1])
	p = [float(p) for p in line2.split(" ")]
	pp = [p[0]]
	for i in xrange(1, len(p)):
		pp += [p[i]*pp[-1]]
	exs = [A+B+1, 1+B+1]
	for i in xrange(A):
		exs += [pp[A-i-1]*(2*i+B-A+1) + (1-pp[A-i-1])*(2*i+B-A+1+B+1)]
	return min(exs)

fin = open("%s.in" % exName, "r")
din = fin.read()
fin.close()

din = din.split("\n")[1:]

fout = open("%s.out" % exName, "w")

for nline in xrange(0, len(din), 2):
	if din[nline] == "": continue
	ln = "%.6f" % solve(din[nline], din[nline+1])
	ln = "Case #%d: %s" % (1+nline/2, ln)
	print ln
	fout.write(ln + "\n")
fout.close()
