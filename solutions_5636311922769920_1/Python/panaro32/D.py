def parse():
	k,c,s = map(int,input().split())
	return k,c,s

def index(p,k):
	return sum(x*k**i for i,x in enumerate(p))

def solve(k,c,s):
	n = k//c + bool(k%c)
	if n > s: return []
	p = list(range(k)) + [0]*(c-k%c)*bool(k%c)
	q = [p[i:i+c] for i in range(0,len(p),c)]
	l = [index(x,k)+1 for x in q]
	return l

def main():
	for i in range(int(input())):
		k,c,s = parse()
		l = solve(k,c,s)
		print("Case #{}:".format(i+1), end="")
		if not l: print(" IMPOSSIBLE")
		else:
			for x in l:
				print(" {}".format(x), end="")
			print("")

if __name__ == "__main__": main()