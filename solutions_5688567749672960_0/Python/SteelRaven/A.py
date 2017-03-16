from queue import Queue

need = 10**6 * 10
edges = [[] for _ in range(need + 1)]
for i in range(1, need):
	edges[i].append(i + 1)
	next = int(''.join(reversed(str(i))))
	if next <= need:
		edges[i].append(next)

l = [10**10] * (need + 1)
l[1] = 1
q = Queue()
q.put(1)
while not q.empty():
	v = q.get()
	for next in edges[v]:
		if l[v] + 1 < l[next]:
			q.put(next)
			l[next] = l[v] + 1

def solve():
	n = int(input())
	return l[n]

t = int(input())
for i in range(t):
	print('Case #{}: {}'.format(i + 1, solve()))
