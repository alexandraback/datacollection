# if its not maximum - spend 

t = int(raw_input())

for i in xrange(0,t):
	# print "Case %d " % i
	E,R,nv = [int(j) for j in raw_input().split()]
	vi = [int(j) for j in raw_input().split()]
	w = max(vi)

	highest = [0] * nv
	index = [0] * nv
	highest[nv-1] = vi[nv - 1]
	index[nv - 1] = nv
	
	for m in xrange(0,nv - 1):
		l = nv - 2 - m
		highest[l] = max(highest[l+1], vi[l])
		index[l] = l + 1 if vi[l] < vi[l+1] else index[l+1]

	# print vi
	# print index

	p = 0
	gain = 0
	en = E
	while p < nv:
		# print p, en, gain
		if R < E:
			if index[p] == nv or vi[p] == highest[p]:
				can = en
			else:
				can = (index[p] - p) * R
				if E - en > 0:
					can -= E - en
				can = max(can , 0)
				can = min(can, en)

			en -= can
			gain += vi[p] * can 

			# print "P1", en, gain

			if index[p] < nv:
				if (en + (index[p] - p) * R) > E:
					p += can / R
					en += R * (can / R)
				else:
					en += (index[p] - p) * R
					p = index[p]
				en = min(en, E)
				# print "P4", en, gain	
			else:
				en += R
				p = p+1
				# print "P3", en, R, gain


		else:
			gain += vi[p] * en
			p += 1

	print "Case #%d: %d" % (i+1, gain)