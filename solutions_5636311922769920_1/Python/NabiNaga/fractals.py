
def build(k,c,l):
	l += [0]*(c-len(l))
	ind = 0
	for x in l:
		ind *= k
		ind += x
	return ind+1

def solve(line):
	k,c,s = [int(x) for x in line.split()]
	if s*c < k:
		return "IMPOSSIBLE"
	need = range(k)
	inds = []
	for i in xrange(0,k,c):
		inds.append(build(k,c,need[i:i+c]))
	return ' '.join([str(x) for x in inds])

output = []
with open('fractal_input.txt') as f:
	t = int(f.readline())
	for i,line in enumerate(f):
		output.append("Case #%d: %s\n" % (i+1,solve(line.strip())))

with open('fractal_output.txt','w') as f:
	for line in output:
		print line,
		f.write(line)