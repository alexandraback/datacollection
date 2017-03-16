from itertools import combinations
from math import sqrt

J = 500

def num(s, base):
	ans = 0
	for i in range(len(s)):
		if s[i] == '1':
			ans += pow(base,i)

	return (ans)

def primo(n):
	if n == 2:
		return -1

	lim = int(sqrt(n))
	lim += 2

	for d in range(3,lim):
		if n % d == 0:
			return d

	return -1

def solve():

	par = [2*i for i in range(1,16)]
	impar = [2*i + 1 for i in range(15)]

	c = 0

	fout = open("out.txt","w")

	fout.write("Case #1:\n")

	for cant in range(2,17,3):

		c1 = combinations(par,cant)
		c2 = combinations(impar,cant)

		for t1 in c1:
			for t2 in c2:
				s = ['0' for i in range(32)]
				divi = [3,2,3,2,7,2,3,2,3]
				s[0] = '1'
				s[-1] = '1'
				for x in t1:
					s[x] = '1'
				for x in t2:
					s[x] = '1'

				nn = [num(s,b) for b in range(2,11)]
				
				c += 1
				t = s[::-1]
				fout.write("".join(t))
				for i in range(len(divi)):
					d = divi[i]
					assert nn[i] % d == 0
					fout.write(" " + str(d))
				fout.write("\n")

				#print "".join(t), c

				if c == J:
					fout.close()
					return

				# for b in range(2,11):
				# 	nb = num(s,b)
				# 	fout.write(str(nb) + " ")
				# 	if b % 2 == 1:
				# 		assert nb % 2 == 0
				# 	if b == 2 or b % 3 == 1:
				# 		assert nb % 3 == 0
				# 	if b == 6:
				# 		assert nb % 7 == 0
				# 	if b == 8:
				# 		assert nb % pn == 0
				# 	fout.write("\n")

	for cant in range(4,14,5):

		c1 = combinations(par,cant)
		c2 = combinations(impar,cant)

		for t1 in c1:
			for t2 in c2:
				s = ['0' for i in range(32)]
				divi = [-1,2,5,2,5,2,-1,2,11]
				s[0] = '1'
				s[-1] = '1'
				for x in t1:
					s[x] = '1'
				for x in t2:
					s[x] = '1'

				nn = [num(s,b) for b in range(2,11)]

				n = num(s,8)
				m = num(s,2)
				pn = primo(n)
				pm = primo(m)
				if pn != -1 and pm != -1:
					c += 1
					t = s[::-1]
					fout.write("".join(t))
					divi[0] = pm
					divi[-3] = pn
					for i in range(len(divi)):
						d = divi[i]
						assert nn[i] % d == 0
						fout.write(" " + str(d))
					fout.write("\n")
					if c == J:
						fout.close()
						return
					# for b in range(2,11):
					# 	nb = num(s,b)
					# 	fout.write(str(nb) + " ")
					# 	if b % 2 == 1:
					# 		assert nb % 2 == 0
					# 	if b == 4 or b == 6:
					# 		assert nb % 5 == 0
					# 	if b == 10:
					# 		assert nb % 11 == 0
					# 	if b == 8:
					# 		assert nb % pn == 0
					# 	if b == 2:
					# 		assert nb % pm == 0
		 			# fout.write("\n")

solve()