from sys import stdin, stdout
t = int(stdin.readline())
def genAll(n):
	if n.count("?") == 0:
		return [n]
	ret = []
	if n.count("?") == 1:
		for i in range(10):
			ret.append(n.replace("?", str(i)))
		return ret
	for i in range(10):
		ret.extend(genAll(n.replace("?", str(i), 1)))
	return ret
for k in range(1, t+1):
	c, j = map(str, stdin.readline().strip().split(' '))
	tlen = len(c)
	c = map(int, genAll(c))
	j = map(int, genAll(j))
	mindiff = 10**5
	minc = -1
	minj = -1
	for i in range(len(c)):
		for l in range(len(j)):
			if abs(c[i]-j[l]) == mindiff:
				if c[i] == c[minc]:
					if j[l] < j[minj]:
						minj = j
				elif c[i] < c[minc]:
					minc = i

			elif abs(c[i]-j[l]) < mindiff:
				mindiff = abs(c[i]-j[l])
				minc = i
				minj = l
	c = "".join(["0" for _ in range(tlen-len(str(c[minc])))]) + str(c[minc])
	j = "".join(["0" for _ in range(tlen-len(str(j[minj])))]) + str(j[minj])
	stdout.write("Case #"+str(k)+": "+str(c)+" "+str(j)+"\n")