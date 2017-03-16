for test in range(int(raw_input())):
	rez = 0
	n = int(raw_input())
	fr = []
	sc = []
	seenk = []
	for i in range(n):
		tf, ts = raw_input().split()
		seenk.append((tf,ts))
	for i in range(n):
		f,s = seenk[i]
		fl1 = False
		fl2 = False
		for j in range(n):
			if(i == j):
				continue
			f2,s2 = seenk[j]
			if(f == f2): fl1 = True
			if(s == s2): fl2 = True

		if(fl1 and fl2):
			rez +=1
	print "Case #{0}: {1}".format(test + 1, rez)