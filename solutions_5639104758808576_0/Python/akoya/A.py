import sys

fin = open(sys.argv[1], "r")
fout = open("A.out", "w")

T = int(fin.readline())
for i in xrange(T):
	a = map(int, fin.readline().split())
	smax = a[0]
	b = str(a[1])
	
	for j in range(smax+1-len(b)):
		b='0'+b
	bring = 0
	summ = 0
	for j in range(smax+1):
		if summ < j:
			bring += j-summ
			summ = j
		summ += int(b[j])

	fout.write("Case #" + str(i+1) + ": " + str(bring) + "\n")
