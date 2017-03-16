def flip(s,n):
	ret = ""
	for i in range(n,-1,-1):
		if s[i] == "-":
			ret += "+"
		else:
			ret += "-"
	for i in range(n+1,len(s)):
		ret += s[i]
	return ret

def done(s):
	return s.find("-") == -1

def solve(s):
	seen = {}
	q = [(s,0)]
	while not done(q[0][0]):
		top = q.pop(0)
		if top[0] not in seen and top[1] < 2*len(top[0]):
			for i in range(len(top[0])):
				q.append((flip(top[0],i),top[1]+1))
			seen[top[0]] = 1
	return q[0][1]

T = int(raw_input())
for i in range(T):
	print "Case #" + str(i+1) + ": " + str(solve(raw_input()))