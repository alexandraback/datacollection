def win(fir,sec):
	bod = len(fir)
	sec_win = 0
	for i in range(bod):
		if fir[-1] < sec[-1]:
			sec_win +=1
			sec.pop()
		fir.pop()
	return sec_win

n = int(raw_input())
for i in range(n):
	print "Case #%d:"%(i+1),
	num = int(raw_input())
	naomi = raw_input().split()
	ken = raw_input().split()
	for k in range(num):
		naomi[k] = float(naomi[k])
		ken[k] = float(ken[k])
	naomi.sort()
	ken.sort()
	naomi1 = naomi[:]
	naomi2 = naomi[:]
	ken1 =  ken[:]
	ken2 = ken[:]

	new = win(ken1,naomi1)
	old = win(naomi2,ken2)
	print new,(num-old)