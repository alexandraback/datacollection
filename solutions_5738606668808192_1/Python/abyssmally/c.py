fout = open("c.out", "w")
fout.write("Case #1:\n")

n = 32
j = 500

primes = [2,3,5,7,11,13,17,19,23,29]

for i in xrange(2**(n-2)):
	string = "1"
	for dig in xrange(n-3,-1,-1):
		if (i & (1<<dig)):
			string += "1"
		else:
			string += "0"
	string += "1"
	proof = []
	for base in xrange(2,11):
		good = 0
		num = int(string, base)
		for prime in primes:
			if num % prime == 0:
				good = 1
				proof.append(str(prime))
				break
		if not good:
			break
	if len(proof) == 9:
		fout.write(" ".join([string] + proof) + "\n")
		j -= 1
		if j == 0:
			break