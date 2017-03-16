import sys

input()
inp = sys.stdin.readlines()
j=0
while inp:
	n = int(inp.pop(0))
	j+=1
	c = [inp.pop(0)[:-1].split() for k in range(n)]
	firsts = list(zip(*c))[0]
	seconds = list(zip(*c))[1]
	a = sum(firsts.count(i[0])>1 and seconds.count(i[1])>1 for i in c)
	print("Case #{}: {}".format(j, a))
