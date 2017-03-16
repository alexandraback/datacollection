from random import randint

def gentest():
	f = open("test.txt","w")
	f.write("100\n")
	for n in range(100):
	    m = randint(100000,1000000)
	    f.write(str(m) + "\n")

def solve(n):
	#n = int(f.readline())
	vis = [False for i in range(10)]
	left = 10

	if n == 0:
		return("INSOMNIA")

	for i in range(1,10000):
		m = str(n*i)
		#print m
		for d in m:
			dd = int(d)
			if not(vis[dd]):
				left -= 1
			vis[dd] = True
		if left == 0:
			return (n*i)

fin = open("test.txt","r")
fout = open("out.txt","w")
t = int(fin.readline())
for caso in range(1,t+1):
	n = int(fin.readline())
	fout.write("Case #" + str(caso) + ": " + str(solve(n)) + "\n")

fin.close()
fout.close()
