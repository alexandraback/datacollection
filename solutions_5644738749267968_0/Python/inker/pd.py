

t = int(raw_input())

for cases in range(1, t+1):
	n = int(raw_input())
	
	arr = raw_input().split(" ")
	arr2 = raw_input().split(" ")
	arr = sorted(arr)
	arr2 = sorted(arr2)

	score1 = score2 = 0
	tmparr = arr2[:]
	for x in arr:
		if any(map(lambda y: y>x, tmparr)):
			tmparr.remove(min(filter(lambda y:y>x, tmparr)))
		else:
			tmparr.remove(min(tmparr))
			score1 = score1 + 1
		#print tmparr
	
	tmparr = arr2[:]
	for x in arr:
		if min(tmparr) < x:
			#print "cond 1"
			score2 = score2 + 1
			tmparr.remove(min(tmparr))
		elif any(map(lambda y: y>x, tmparr)):
			#print "cond 2"
			tmparr.remove(max(tmparr))
		else:
			#print "cond 3"
			tmparr.remove(min(tmparr))
			score2 = score2 + 1
		#print tmparr

	print "Case #{0}: {1} {2}".format(cases, score2, score1)

