from sets import Set
def getpermutation(N):
	reta = [[0]]
	for i in range(1,N):
		cura = []
		for s in reta:
			for j in range(0,len(s)):
				tmp = []
				tmp.extend(s[:j])
				tmp.append(i)
				tmp.extend(s[j:])
				cura.append(tmp)
			tmp = []
			tmp.extend(s)
			tmp.append(i)
			cura.append(tmp)
		reta = cura
	return reta


linearray = []

fp = open('B-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

cd = {}
mm = 1000000007
T = int(linearray[0])
op = open('output.txt','w')
for i in range(0,T):
	N = int(linearray[2*i+1])
	splits = linearray[2*i+2].split()
	
	
	
	for j in range(0,26):
		cd[j] = []
		for s in range(len(splits)):
			if splits[s].find(chr(j+97)) != -1:
				cd[j].append(s)
				#print j,chr(j+97),cd[j]

	valid = 0
	psbarray = []
	mtarray = []
	mharray = []
	for j in range(0,26):
		curch = chr(97+j)

		cur = cd[j]
		if (len(cur)<=0):
			psbarray.append(0)
			mharray.append([])
			mtarray.append([])
			continue

		notall = []
		for ci in range(0,len(cur)):
			other = False
			for anoj in range(0,26):
				if (anoj == j): continue
				if splits[cur[ci]].find(chr(anoj+97)) != -1:
					other = True
					break
			if (other):
				notall.append(cur[ci])
		#print curch,notall
		if (len(notall) > 2):
			valid = -1
			break
		
		musthead = []
		musttail = []
		for k in notall:
			if (not splits[k].startswith(curch)):
				musthead.append(k)
			if (not splits[k].endswith(curch)):
				musttail.append(k)

			stt = splits[k].find(curch)
			end = splits[k].rfind(curch)
			for it in range(stt,end):
				if (splits[k][it] != curch):
					valid = -1
			if (valid == -1): break

		if (valid == -1 or len(musthead) > 1 or len(musttail)>1):
			valid = -1
			break

		if (len(musthead)>=1 and musthead == musttail and len(cur) > 1):
			valid = -1
			break
		#print j,musthead,musttail
		psb = 1
		inc = 1
		for k in cur:
			if (k in musthead or k in musttail): continue
			psb = (psb * inc) % mm
			inc += 1

		psbarray.append(psb)
		mharray.append(musthead)
		mtarray.append(musttail)

	if (valid == -1):
		print i,0
		op.write("Case #%s: 0\n" % (i+1))
		continue

	g = 0
	includedj = Set([])
	for j in range(0,26):
		if (len(cd[j]) <= 0):
			includedj.add(j)
			continue
		if (len(cd[j]) == 1):
			if len(mharray[j]) == 0 and len(mtarray[j]) == 0:
				g += 1
				includedj.add(j)				
			elif (len(mharray[j]) == 1 and len(mtarray[j]) == 1):
				includedj.add(j)

	m = []
	for j in range(0,26):
		if (j in includedj): continue
		if (len(mharray[j]) == 0 and len(mtarray[j]) == 0):
			m.append(psbarray[j])
			g += 1
			includedj.add(j)
		else:
			includedj.add(j)
			psb = psbarray[j]
			musthead = mharray[j]
			musttail = mtarray[j]
			while (len(musthead) > 0):
				head = musthead[0]
				adj = -1
				for jj in range(0,26):
					if (head in mtarray[jj] and not jj in includedj):
						adj = jj
						break
				includedj.add(adj)
				psb = psb * psbarray[adj] % mm
				musthead = mharray[adj]
			while (len(musttail) > 0):
				tail = musttail[0]
				adj = -1
				for jj in range(0,26):
					if (tail in mharray[jj] and not jj in includedj):
						adj = jj
						break
				includedj.add(adj)
				psb = psb * psbarray[adj] % mm
				musttail = mtarray[adj]
			g += 1
			m.append(psb)

	psb = 1
	for mv in m:
		psb = psb * mv % mm
	for gg in range(1,g+1):
		psb = psb * gg % mm
	print i,psb
	op.write("Case #%s: %s\n" % (i+1,psb))
op.close()