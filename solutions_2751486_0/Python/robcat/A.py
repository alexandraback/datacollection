import sys
N = int(sys.stdin.readline())
for case in range(N):
	name, n = sys.stdin.readline().split()
	n = int(n)
	i = 0	
	for s in range(len(name)-n+1):
		for e in range(len(name),s+n-1,-1):
			j = 0
			for l in name[s:e]:
				if l not in ('a','e','i','o','u'):
					j += 1
					if j>= n: break
				else:
					j=0
					continue
			if j>=n:
				i+=1
	print("Case #%s: %s" % (str(case+1), i))
