fin = open("C-large.in", "r")
fout = open("C-large.out", "w")
n = int(fin.readline())
for i in range(n):
	a, b = map(int, fin.readline()[:-1].split())
	ans = 0
	for j in range(a, b+1):
		number = j
		count = {}
		count[number] = 1
		for k in range(len(str(j))-1):
			number = number/10 + (number%10)*(10**(len(str(j))-1))
			if number>=a and number<=b:
				count[number] = 1
		ans += len(count) - 1
	fout.write("Case #%d: %d\n" % (i+1, ans/2))
	print "get"
			
fin.close()
fout.close()

