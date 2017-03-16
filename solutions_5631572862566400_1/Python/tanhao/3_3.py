import numpy as np
import sys

def dfs(now, order):
	
	#print order - start
	#visited[i] = order
	#print now
	if visited[now] != 0:
		if visited[now] >= start:
			#length[now] = order - visited[now]
			tmp = order - visited[now]
			circle[now] = tmp
			#ans = max(ans, tmp)
			
			#if length[now] == 2:
				#extensible[now] = 1
			return now, True, order
		else:
			return label[now], False, order
	visited[now] = order
	#order += 1
	start_of_circle, in_circle, last_order = dfs(a[now], order + 1)
	#print start_of_circle, last_order
	if in_circle == False:
		label[now] = start_of_circle
		length[now] = length[a[now]] + 1
		return start_of_circle, False, last_order
	else:
		label[now] = now
		length[now] = 0 #length[a[now]]
		if start_of_circle == now:
			return start_of_circle, False, last_order
		else:
			return start_of_circle, True, last_order

sys.setrecursionlimit(10000)
f = open("3.in")
test_num = int(f.readline()[:-1])
for test_case in xrange(1, test_num + 1):
	#print "case", test_case
	n = int(f.readline()[:-1])
	a = [int(x) - 1 for x in f.readline().split()]
	visited = np.zeros(n, dtype = np.int32)
	length = np.zeros(n, dtype = np.int32)
	circle = np.zeros(n, dtype = np.int32)
	extensible = np.zeros(n, dtype = np.int32)
	label = np.zeros(n, dtype = np.int32)
	ans = 0
	order = 1
	for i in xrange(len(a)):
		if visited[i] != 0:
			continue
		start = order
		#print i, dfs(i, order)
		hehe, haha, order = dfs(i, order)
		#print i, order
		#print list(visited)
		#print list(length)
		#print list(label)
	for i in xrange(len(a)):
		extensible[label[i]] = max(extensible[label[i]], length[i])
	#print "circle", list(circle)
	ans = max(circle)
	tmp = 0
	for i in xrange(len(a)):
		if a[a[i]] == i:
			tmp = tmp + 2 + extensible[i] + extensible[a[i]]
			#ans = max(ans, tmp)
	ans = max(ans, tmp / 2)
	#print "extened", list(extensible)
	print "Case #%d: %d" %(test_case, ans)
	
	#ans = max(length)
	#print ans

	
