T = int(raw_input())

for t in xrange(1,T+1):
	N = int(raw_input())
	Graph = []
	for i in xrange(N):
		Graph.append((i+1,map(int,(raw_input().split())[1:])))

	PossibleSources = filter(lambda (x,y): len(y)>1, Graph)
	flag = 0
#	print PossibleSources
	for s in PossibleSources:
		Expanded = []
		ToExpand = [s[0]]
		height = 0
		while ToExpand!=[] and height < N+3 and flag != 1:
			Visited = Graph[ToExpand[0]-1][1]
			if filter(lambda v: v in Expanded, Visited):
				flag = 1
			elif filter(lambda v: v in ToExpand, Visited):
				flag = 1
			else:
				Expanded.append(ToExpand.pop(0))
				ToExpand.extend(Visited)
				height += 1
		if flag == 1:
			print 'Case #' + str(t) + ': Yes'
			break
	if flag == 0:	
		print 'Case #' + str(t) + ': No'
				
			
