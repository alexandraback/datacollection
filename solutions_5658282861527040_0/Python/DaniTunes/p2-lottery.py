import sys

def solve(a, b, k):
    n = 0
    for i in range(a):
	for j in range(b):
	    if (i & j) < k:
		n += 1
    return n

data = sys.stdin.readlines()
n = int(data[0])
for i in range(n):
    a, b, k = map(int, data[i+1].split())
    print "Case #%d:" % (i+1), solve(a, b, k)

