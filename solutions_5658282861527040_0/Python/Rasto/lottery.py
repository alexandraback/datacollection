import fileinput

def solve(a, b, k):
	return sum(1 for j in range(b) for i in range(a) if i&j < k)

f = fileinput.input()
tt = int(f.readline())
for t in range(tt):
	a, b, k = tuple(map(int, f.readline().rstrip().split()))
	print("Case #%d:" % (t+1), solve(a, b, k))