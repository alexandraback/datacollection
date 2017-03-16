lines = open('A-small-attempt1.in').read().split('\n')
T = int(lines[0])
output = []
for t in xrange(1, T+1):
	a = [int(x) for x in lines[t].split()]
	N = a[0]
	a=a[1:]
	_sum = 2 * float(sum(a))
	minx = _sum/N
	r = [ max(0, (minx-x)*100/_sum) for x in a]
	output.append("Case #"+str(t)+": "+" ".join(["%.6f" % k for k in r]))
open("a.out", "w").write("\n".join(output))