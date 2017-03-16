def solve():
	x, r, c = (int(t) for t in input().split())
	if r * c % x:
		return 'RICHARD'
	if x > max(r, c):
		return 'RICHARD'
	if x > min(r, c) * 2:
		return 'RICHARD'
	if x == 4 and min(r, c) <= 2:
		return 'RICHARD'
	return 'GABRIEL'

n = int(input())
for t in range(n):
	print("Case #{}: {}".format(t + 1, solve()))
