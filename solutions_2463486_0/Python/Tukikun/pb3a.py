import math
from time import time

f = open('input.dat', 'r')
out = open('5.out', 'w')

nb = int(f.readline())

def getline(file):
	line = f.readline()
	line = line.replace("\n", '')
	line = line.replace(' ', ',')
	L = eval('['+line+']')
	return L

def isp(sn):
	for k in range(math.ceil(len(sn)/2)):
		if sn[k]!=sn[len(sn)-1-k]:
			return 0
	return 1

start = time()
sols = []
max=1000
a = 1
b=math.ceil(math.sqrt(max+1))
for j in range(a,b+1):
	if isp(str(j)):
		j2=j*j
		if j2 <= max:
			sj2 = str(j2)
			if isp(sj2):
				sols = sols + [j2]

print(sols)
print((time() - start),"s")

for i in range(nb):
	A, B = getline(f)
	tot=0
	for s in sols:
		if s>= A and s<= B:
			tot = tot+1
	out.write("Case #%d: %d\n"%(i+1,tot))

out.write("\n")
out.close()



