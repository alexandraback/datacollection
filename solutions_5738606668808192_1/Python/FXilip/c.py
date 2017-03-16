with open("C-large.in") as f:
	dat = f.read().splitlines()

def get_prime(n):
	#for i in range(2,int(n**0.5)+1):
	for i in range(2,1000):
		if n%i == 0:
			return i
	return -1
def ninbase(digs,base):
	n = 0
	mul = 1
	for d in digs:
		n += mul*d
		mul *= base
	return n
	
n = int(dat[0])
out = ["Case #1:"]

N = int(dat[1].split()[0])
J = int(dat[1].split()[1])
	
for jc in range(2**(N-1)+1,2**N-1,2):
	jc = str(bin(jc))[2:]
	#print(jc)
		
	jcd = list(jc)[::-1]
	jcd = [int(jj) for jj in jcd]
	primes = []
	for base in range(2,11):
		n = ninbase(jcd,base)
		primes.append(get_prime(n))
		if -1 in primes:
			break
	#print(primes)
		
	if -1 not in primes:
		out.append(jc+" "+" ".join([str(p) for p in primes]))
		print(out[-1])
	if out.__len__() == J+1:
		break

assert out.__len__() == 1+J
of = open("out.txt","w")
of.write("\n".join(out))
of.close()



