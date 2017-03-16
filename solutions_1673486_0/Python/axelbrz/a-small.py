exName = "a-small"

# str to str
def solve(line1, line2):
	A, B = int(line1.split(" ")[0]), int(line1.split(" ")[1])
	p = [float(p) for p in line2.split(" ")]
	exs = []
	pp = []
	if A == 1:
		pp += [p[0]]#g
		pp += [1-p[0]]#X
		exs += [pp[0] * (B-A+1) + pp[1] * (B-A+1+B+1)]#keep
		exs += [1+B+1]#1
		exs += [1+B+1]#away
	elif A == 2:
		pp += [p[0]*p[1]]#gg
		pp += [p[0]*(1-p[1])]#gX
		pp += [(1-p[0])*p[1]]#Xg
		pp += [(1-p[0])*(1-p[1])]#XX
		
		exs += [pp[0]*(B-A+1) + (pp[1]+pp[2]+pp[3])*(B-A+1+B+1)]#keep
		exs += [(pp[0]+pp[1])*(1+1+B-A+1) + (pp[2]+pp[3])*(1+1+(B-A)+1+B+1)]#1
		exs += [2+B+1]#2
		exs += [1+B+1]#away
		
	elif A == 3:
		pp += [(p[0])*(p[1])*(p[2])]#ggg 0
		pp += [(p[0])*(p[1])*(1-p[2])]#ggX 1
		pp += [(p[0])*(1-p[1])*(p[2])]#gXg 2
		pp += [(p[0])*(1-p[1])*(1-p[2])]#gXX 3
		pp += [(1-p[0])*(p[1])*(p[2])]#Xgg 4
		pp += [(1-p[0])*(p[1])*(1-p[2])]#XgX 5
		pp += [(1-p[0])*(1-p[1])*(p[2])]#XXg 6
		pp += [(1-p[0])*(1-p[1])*(1-p[2])]#XXX 7
		
		exs += [(pp[0])*(1+B-A) + sum(pp[1:])*(B-A + 1 + B + 1)]#keep
		exs += [(pp[0]+pp[1])*(1+1+B-A+1) + (sum(pp[2:]))*(1+1+B-A+1+B+1)]#1
		exs += [sum(pp[:4])*(2+2+B-A+1) + (sum(pp[4:]))*(2+2+B-A+1+B+1)]#2
		exs += [3+B+1]#3
		exs += [1+B+1]#away
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
