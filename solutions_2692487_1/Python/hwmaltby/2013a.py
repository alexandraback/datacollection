f = open('A-large.in', 'r')

T = int(f.readline())

max_size = lambda x, y: x + y if y < x else max_size(2 * x - 1, y)
min_time = lambda x, y: 0 if y < x else 1 + min_time(2 * x - 1, y)

def min_changes(A, motes):
	if len(motes) == 0:
		return 0
	tmp = motes[0]
	if A > tmp:
		return min_changes(A + tmp, motes[1:])
	return min(len(motes), min_time(A, tmp) + min_changes(max_size(A, tmp), motes[1:]))

for i in range(T):
	A, N = map(int, f.readline().split())

	motes = list(map(int, f.readline().split()))
	motes.sort()

	if A == 1:
		ans = len(motes)
	else:
		ans = min_changes(A, motes)

	print(("Case #" + str(i + 1) + ": " + str(ans)))
