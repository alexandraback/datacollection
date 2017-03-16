import sys

T = input()

for t in range(T):
	N = input()
	graph = list()
	for n in range(N):
		data = raw_input()
		data = data.split()[1:]
		data = [int(i)-1 for i in data]
		graph.append(data)
	
	qq = list()
	check = False
	for i in range(N):
		for go in graph[i]:
			qq.append(go)

		mypath = [0 for i in range(N)]
		while True:
			if len(qq) == 0: break
			now = qq[0]
			qq.pop(0)
			mypath[now] += 1
			if mypath[now] > 1:
				print("Case #%d: Yes" % (t+1))
				check = True
				break

			for go in graph[now]:
				qq.append(go)


		if check: break
	
	if not check : print("Case #%d: No" % (t+1))

