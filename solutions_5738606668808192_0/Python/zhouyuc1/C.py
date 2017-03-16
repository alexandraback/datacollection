from gen_prime import find_primes

plist = find_primes(10000)

def trans(num, base):
	ret = 0
	sift = 1
	pwr = 1
	while sift <= num:
		if sift & num:
			ret += pwr
		pwr *= base
		sift <<= 1
	return ret

def find_fact(num):
	ret = -1
	for fact in plist:
		if fact * fact > num:
			break
		if num % fact == 0:
			ret = fact
			break
	return ret

def bin2str(num):
	ret = ''
	while num > 0:
		if num & 1:
			ret = '1' + ret
		else:
			ret = '0' + ret
		num >>= 1
	return ret

infile = open('C.in', 'r')
outfile = open('C.out', 'w')

infile.readline()
N, J = [int(x) for x in infile.readline().split()]
outfile.write('Case #1:\n')

num = (1<<(N-1))+1
factlist = [0]*11
cnt = 0

while cnt < J:
	for base in range(2, 11):
		testnum = trans(num, base)
		factlist[base] = find_fact(testnum)
	check = sum(x == -1 for x in factlist)
	if (check == 0):
		cnt += 1
		outfile.write(bin2str(num))
		for base in range(2, 11):
			outfile.write(' %d' % factlist[base])
		outfile.write('\n')
	num += 2

infile.close()
outfile.close()








