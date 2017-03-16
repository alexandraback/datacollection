import math

fin = open('C-large.in', 'r')
fout = open('C-large.out','w')


def GrayCodeBitToFlip(i):
	return 0 if (i % 2 == 1) else (1 + GrayCodeBitToFlip(i/2))

def TestJamCoin(jam):
	ret = None
	divisors = []
	for base in range(2,11):
		num = sum([jam[b]*(base**(b+1)) for b in range(len(jam))]) + 1 + (base**(len(jam)+1))
		
		upper = min(100000,int(math.sqrt(num)))
		div = 0
		d = 2
		
		while d <= upper:
			if num % d == 0:
				div = d
				break
			d = d + 1
		
		if div == 0:
			break
		
		divisors.append(str(div))
	
	if len(divisors) == 9:
		ret = "1" + "".join(reversed([str(jm) for jm in jam])) + "1 " + " ".join(divisors)
	
	return ret

numlines = int(fin.readline().rstrip())

for line in range(numlines):
	val = str(fin.readline().rstrip())
	vals = [int(v) for v in val.split(" ")]
	
	results = []
	jam = [0]*(vals[0]-2)
	attempt = 0
	while(len(results) < vals[1]):
		attempt = attempt + 1
		bit = GrayCodeBitToFlip(attempt)
		
		jam[bit] = 1 - jam[bit]
		
		outstr = TestJamCoin(jam)
		if outstr != None:
			results.append(outstr)
			# print outstr
	
	outstr = "Case #" + str(line+1) + ":\n" + "\n".join(results) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)


