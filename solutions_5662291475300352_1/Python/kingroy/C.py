import sys

T = int(sys.stdin.readline())
for i in range(T):
	q = []
	N = int(sys.stdin.readline())
	for j in range(N):
		string = sys.stdin.readline().split(' ')
		start = int(string[0])
		hiker = int(string[1])
		fast = int(string[2])
		for k in range(hiker):
			q.append([(360.0 - start) * (fast + k) / 360.0, True, fast + k])
	q = sorted(q, key=lambda x:x[0])
	onFirst = len(q)
	ans = onFirst
	curr = onFirst
	while curr - onFirst < ans:
		minus = 0
		add = 0
		t = q[0][0]
		while minus + add < len(q) and t == q[minus + add][0]:
			q[minus + add][0] += q[minus + add][2]
			if q[minus + add][1]:
				q[minus + add][1] = False
				minus += 1
			else:
				add += 1
		onFirst -= minus
		curr += add - minus
		if (ans > curr):
			ans = curr
		q = sorted(q, key=lambda x:x[0])
	print "Case #%d: %d" % (i + 1, ans)
