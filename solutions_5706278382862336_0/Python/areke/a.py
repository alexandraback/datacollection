#Template File for GCJ
def solve(a, b):
	f = 0.5
	gen = 1
	x = (a/b)*(2**40)
	if x != (x-x%1):
		return "impossible"
	else:
		d = a/b
		while f > a/b:
			f/=2
			gen+=1
	return gen


f = open("/Users/mklein16/Desktop/gcj/A-small-attempt0.in", 'r')
contents = f.read()
cases = int(contents.split("\n")[0])
contents = contents.split("\n")[1:]
for i in xrange(cases):

	a, b = contents[i].split("/")
	a = float(a)
	b = float(b)
	ans = solve(a, b)


	f.close()
	g = open("/Users/mklein16/Desktop/gcj/output.txt", 'a')
	g.write("Case #" + `i+1`+": " + str(ans) + "\n")
	g.close()