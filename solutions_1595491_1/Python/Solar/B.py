fin = open("B-large.in", "r")
fout = open("B-large.out", "w")
n = int(fin.readline())
for i in range(n):
	data = map(int, fin.readline()[:-1].split())
	n = data[0]
	s = data[1]
	p = data[2]
	scr = data[3:]
	ans = 0
	for score in scr:
		if score%3 == 0:
			if score/3 >= p:
				ans += 1
			elif score != 0 and score/3+1 >= p and s>0:
				ans += 1
				s -= 1
		elif score%3 == 1:
			if score/3+1 >= p:
				ans+=1
		elif score%3 == 2:
			if score/3+1 >= p:
				ans += 1
			elif score/3+2 >= p and s>0:
				ans += 1
				s -= 1
	fout.write("Case #%d: %d\n" % (i+1, ans))
fin.close()
fout.close()
