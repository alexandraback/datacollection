def path(k, c):
	p = []
	for i in range(1, k + 1, c):
		p.append([])
		j = i
		for _ in range(c):
			p[-1].append(j)
			j = min(j + 1, k)
	return p

def p2i(k, c, p):
	idx = 0
	for i in range(c):
		idx += (p[i] - 1) * k ** (c - i - 1)
	idx += 1
	return idx
	
def solve(k, c, s):
	ps = path(k, c)
	if len(ps) > s:
		return "IMPOSSIBLE"
	ids = []
	for p in ps:
		ids.append(str(p2i(k, c, p)))
	return " ".join(ids)
	
t = int(raw_input())
for case in range(1, t + 1):
	k, c, s = map(int, raw_input().split())
	print "Case #%i: %s" %(case, solve(k, c, s))
	
      
        
