from collections import deque
import heapq

number_cases = int(raw_input())

def solve(val):
	if val < 10:
		return val
	visited = set()
	frontier = deque([(1, 1)])
	visited.add(1)
	while frontier:
		next = frontier.popleft()
		if next[0] == val:
			return next[1]
		l = int("".join(list(reversed(str(next[0])))))
		if l not in visited:
			visited.add(l)
			frontier.append((l, next[1] + 1))
		if (next[0] + 1) not in visited:
			visited.add(next[0] + 1)
			frontier.append((next[0] + 1, next[1] + 1))

for i in xrange(number_cases):
	ss = int(raw_input())
	print "Case #{}: {}".format(i+1, solve(ss))