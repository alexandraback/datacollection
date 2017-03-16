def solve(n):
	S = []
	x = int(n)
	for i in range(x+1):
		if i < 12:
			S.append(i)
		else:
			rev = int(str(i)[::-1])
			if rev < i and  (i % 10 > 0):
				ans = min(S[i-1] + 1, S[rev] + 1)
				S.append(ans)
			else:
				S.append(S[i-1] + 1)

	return S[len(S)-1]

def dosolve(f,g):
	d = f.read().split("\n")
	n = int(d[0])

	j = 1
	for i in range(1,n+1):
		g.write ("Case #" + str(i) + ": " + str(solve(d[i])) + "\n")

	return 0

# def solve_large():
# 	g = open("A-large-out.txt","w")
# 	f = open("A-large.in","r")
# 	dosolve(f,g)

def solve_small():
	g = open("A-small-out3.txt","w")
	f = open("A-small-attempt1.in","r")
	dosolve(f,g)

def solve_examples():
	g = open("A-eg-out.txt","w")
	f = open("A-eg.in","r")
	dosolve(f,g)
	
# solve_examples()
solve_small()
# solve_large