for t in range(int(raw_input())):
	C, D, V = map(int, raw_input().strip().split())
	coin = map(int, raw_input().strip().split())
	cnt = 0
	value=[]
	for i in range(0,len(coin)):
		if len(value)==0:
			value+=[coin[i]]
		else:
			tmp = []
			for j in value:
				tmp += [coin[i]+j]
			value += [coin[i]]
			value += tmp
	empty=[]
	tmp=[]
	for i in range(1,V+1):
		if i not in value:
			empty +=  [i]
	while(len(empty)>0):
		if empty[0] not in value:
			cnt+=1
			for j in value:
				tmp += [empty[0]+j]
			value += tmp
			value += [empty[0]]
		empty=empty[1:]
	print 'Case #%d: %d ' % (t + 1, cnt)
	