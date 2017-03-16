import itertools
import sys

input()
for i, c in enumerate(sys.stdin):

	z=len(c.split()[0])
	n=c.count("?")
	c=c.replace("?", "{}")
	a=[]
	for p in itertools.product("0123456789", repeat=n):
		a.append([int(i) for i in c.format(*p).split()])
	v=min(a, key=lambda y:[abs(y[0]-y[1])]+y)
	print("Case #{}: {}".format(i+1, " ".join(str(i).zfill(z) for i in v)))
