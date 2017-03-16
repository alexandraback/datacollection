from collections import deque

LIMIT = 1000005

def reverse(x):
	return int(str(x)[::-1])

dp = {}
queue = deque()

def update(i, v):
	if i > LIMIT:
		return
	if dp.get(i) is None:
		dp[i] = v
		queue.append(i)

dp[1] = 1
queue.append(1)

while len(queue) > 0:
	now = queue.popleft()
	update(reverse(now), dp[now] + 1)
	update(now + 1, dp[now] + 1)

#for i in xrange(2, 100):
#	print i, dp[i]
f = open('A-small-attempt0.in', 'r')
out = open('A-small.out', 'w')
T = int(f.readline())
for t in xrange(T):
	tmp = int(f.readline())
	out.write('Case #' + str(t + 1) + ': ' + str(dp[tmp]) + '\n')


