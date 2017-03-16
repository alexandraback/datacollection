import numpy as np

def convert(a,b):
	r = 0
	for i in a:
		r *= b
		r += int(i)
	return r

def isprime(n):
    '''check if integer n is a prime'''
    # make sure n is a positive integer
    n = abs(int(n))
    # 0 and 1 are not primes
    if n < 2:
        return False
    # 2 is the only even prime number
    if n == 2: 
        return True    
    # all other even numbers are not primes
    if not n & 1: 
        return False
    # range starts with 3 and only needs to go up the squareroot of n
    # for all odd numbers
    for x in range(3, int(n**0.5)+1, 2):
        if n % x == 0:
            return False
    return True

def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        if (n % d) == 0:
            primfac.append(d)  # supposing you want multiple factors repeated
            break
        d += 1
    return primfac
def isok(base):
	factors=''
	number = bin(base)[2:]#string of 1 and 0
	for i in range(2,11):
		converted = convert(number,i)
		print(converted)
		if(not isprime(converted)):
			factors +=' '+str(primes(converted)[0])
		else:
			return None
	return factors

def getAnswer(N):
	good=[]
	J = 16
	base = 1+2**(J-1)
	add = 2
	while len(good)<50:
		answer = isok(base)
		if answer:
			good.append(bin(base)[2:]+answer)
		base = base+add
	return good

results=[]
with open('mock.txt','r') as f: #B-small-attempt0.in.txt
	k=0
	for line in f:
		if(k>0):
			N = line
			results.append(getAnswer(N))
			if 'str' in line:
				break
		k+=1

with open('answers.txt','wb') as f:
	f.write("Case #1:\n")
	for i in range(len(r)):
		# f.write("Case #"+str(i+1)+": ")
		f.write(str(r[i]))
		f.write("\n")

