prime = []
i = 2
while i <= 200000:
	flag = 1
	for j in range(0, len(prime)):
		if prime[j] * prime[j] > i:
			break
		if i % prime[j] == 0:
			flag = 0
			break
	if flag == 1:
		prime.append(i)
	i = i + 1

N = 16
J = 50
#X = "1000000000000001"


inputfile = open('C-large.in.txt','r')
outputfile = open('C-large.out.txt','w')

T = inputfile.readline()
T = int(T)
for t in range(1, T + 1):
	outputfile.write('Case #%d:\n'%(t))
	data = inputfile.readline()
	data = data.split()
	N = int(data[0])
	J = int(data[1])
	X = '1'
	for k in range (0, N - 2):
		X = X + '0'
	X = X + '1'
	jth = 0
	while jth < J:
		flag = 1
		for i in range (2, 11):
			x = int(X, i)
			isPrime = 1
			for j in range(0, len(prime)):
				if prime[j] * prime[j] > x:
					break
				if x % prime[j] == 0:
					isPrime = 0
					break
			if isPrime == 1:
				flag = 0
				break
		if flag == 1:
			outputfile.write(X)
			jth = jth + 1
			for i in range (2, 11):
				x = int(X, i)
				for j in range(0, len(prime)):
					if x % prime[j] == 0:
						outputfile.write(' %d'%(prime[j]))
						break
			outputfile.write('\n')
		x = int(X, 2)
		x = x + 2
		X = bin(x)[2:]

inputfile.close()
outputfile.close()
