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
'''
while len(queue) > 0:
	now = queue.popleft()
	update(reverse(now), dp[now] + 1)
	update(now + 1, dp[now] + 1)
'''


#for i in xrange(2, 100):
#	print i, dp[i]

pow10 = [10**i for i in xrange(10)]

def digits(x):
	return len(str(x))

def go(x):
	tmp = 0
	while x > 0:
		#print x
		if x <= 20:
			tmp += x
			x = 0
		else:
			p10 = pow10[digits(x) / 2]
			diff = (x % p10 + p10 - 1) % p10
			tmp += diff + 1
			x -= diff
			#print x
			rev = reverse(x)
			#print rev
			if x <= rev:
				x -= 10
				tmp += 9
			else:
				x = rev
		#print x

	return tmp

f = open('A-large.in', 'r')
out = open('A-large.out', 'w')
T = int(f.readline())
for t in xrange(T):
	tmp = int(f.readline())
	ans = go(tmp)
	#if ans != dp[tmp]:
	#	print tmp, ans, dp[tmp]
	#out.write('Case #' + str(t + 1) + ': ' + str(dp[tmp]) + '\n')
	out.write('Case #' + str(t + 1) + ': ' + str(ans) + '\n')

while True:
	a = int(raw_input())
	#print dp[a]
	print go(a)

