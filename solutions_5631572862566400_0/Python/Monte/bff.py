#BFFS

def addFriends(rmp,best):
	better = best
	if best[-1] not in rmp:
		return better
	for k in rmp[best[-1]]:
		if k in best:
			continue
		else:
			b = addFriends(rmp,best+[k])
			if len(b) > len(better):
				better = b

	if best[0] not in rmp:
		return better

	for k in rmp[best[0]]:
		if k not in better:
			better.append( k)
			break

	return better

T = int(raw_input())
for test in range(T):
	kids = int(raw_input())
	bffs = [int(x) for x in raw_input().split(' ')]
	mp = {}
	rmp = {}
	for i in range(kids):
		mp[i+1] = bffs[i]
		if bffs[i] in rmp:
			rmp[bffs[i]].append(i+1)
		else:
			rmp[bffs[i]] = [i+1]

	best = []
	extra = []
	for k in mp:
		l = []
		l.append(k)
		i = k
		while mp[i] not in l:
			l.append(mp[i])
			i = mp[i]

		if len(l) == kids and mp[l[-1]] == l[0]:
			best = l
			break
		if len(l) <  kids or mp[l[-1]] == l[0]:
			if len(best) != 0 and  mp[best[-1]] == best[-2] and len(l) == 2 and len(list(set(l) & set(best))) == 0:
				extra += l
				# print "Adding {0} to {1}".format(l,best)

			elif len(l) > len(best):
				best = l


	# if len(best) == kids:

	# 	continue
	
	r = addFriends(rmp,best)
	# if test+1 > 0:
	# 	print mp
	# 	print best
	# 	print r
	# print r
	# print len(r)
	# if len(best+extra) < len(r):
	# 	print "Should not have  put extra !"
	# 	print best+extra
	# 	print r
	maxLen = max(len(best+extra), len(r))


		
	print "Case #{0}: {1}".format(test + 1,maxLen)