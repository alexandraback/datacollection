import math
from template import * 

readFile('coinjam')

def is_prime(n):
	for i in range(100):#int(math.sqrt(n))):
		if n%(i+2)==0:
			return i+2
	return True

def to_base(s,b):
	i = b**(len(s)-1)
	r =0 
	for c in s:
		if c=='1':
			r+=i
		i/=b
	return r

answerLn("Case #1:")

N = 32
J = 500

v = 2**(N-1)+1

found = 0
while found<J:
	v+=2
	s = bin(v)[2:] 
	works = True
	ou = []
	for w in range(2,11):
		conv = to_base(s,w)
		ret = is_prime(conv)
		if ret == True:
			works = False
			break
		else:
			ou.append(ret)
	if works:
		answer(str(s)+" ")
		for i in ou:
			answer(str(i)+" ")
		found +=1
		answerLn("")

