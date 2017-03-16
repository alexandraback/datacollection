import sys

fin = open(sys.argv[1], "r")
fout = open("B.out", "w")

def ceildiv(a, b):
    return -(-a // b)        

T = int(fin.readline())
for i in xrange(T):
	length = int(fin.readline())
	a = map(int, fin.readline().split())

	maxelem = max(a)
	solmin = maxelem
	for boxsize in range(1,maxelem):
		num = 0
		for elem in range(len(a)):
			if a[elem] % boxsize > 0:
				num += a[elem] // boxsize
			else:
				num += (a[elem] // boxsize) -1 	
		sol = boxsize + num
		print boxsize, num, sol
		if sol < solmin:
			solmin = sol	
	



	fout.write("Case #" + str(i+1) + ": " + str(solmin) + "\n")