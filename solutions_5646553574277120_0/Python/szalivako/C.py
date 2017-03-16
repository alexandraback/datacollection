T = int(raw_input())
for ti in xrange(T):
	C, D, V = map(int, raw_input().split())
	values = map(int, raw_input().split())
	values.sort()
	ans = 0
	
	for vi in xrange(1, V + 1):
		index = []
		for i in xrange(D):
			index.append(0)
		ok = False
		rest = []
		while (index[-1] <= C):
			sum = 0
			for i in xrange(D):
				sum += values[i] * index[i]
			if (sum == vi):
				ok = True
				break
			else:
				if (vi > sum):
					rest.append(vi-sum)
			i = 0
			while (i < D and index[i] == C):
				index[i] = 0
				i += 1
			if (i == D):
				break
			else:
				index[i] += 1
		
		if (ok == False):
			rest.sort(reverse=True)
			for ri in rest:
				if (not (ri in values)):
					values.append(ri)
					values.sort()
					D += 1
					ans += 1
					break
		#print values
	print 'Case #' + str(ti + 1) + ': ' + str(ans)