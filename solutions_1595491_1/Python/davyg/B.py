

def c(x):
	if x%3 == 0:
		return 0
	else:
		return 1

N = int(raw_input())
for j in range(0, N):
	s = raw_input()
	v = s.split()
	v = map(int, v)
	T = v[0]
	S = v[1]
	p = v[2]
	t = v[3:]
	
	base = map(lambda x : int(x/3) + c(x), t)
	g = [i for i in range(0, len(base)) if base[i] >= p]
	r = len(g)
	t = [t[i] for i in range(0, len(t)) if not i in g and t[i] > 1]
	
	base = map(lambda x : int((x-2)/3) + 2, t)
	g = [i for i in range(0, len(base)) if base[i] >= p]
	r += min(len(g), S)
	
	print("Case #{i}: {r}".format(i=j+1,r=r))
