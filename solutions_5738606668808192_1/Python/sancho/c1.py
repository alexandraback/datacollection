import sys, math, random, time	     

inf = open("in32", "r", encoding="utf-8")
ouf = open("out32", "w", encoding="utf-8")	         
                    
def bit(n, pos):
	return (n & (1 << pos)) > 0

def to2(n):
	return bin(n)[2:]
                             
def pwr(a, b):                 
	res = 1
	while b:
		if (b % 2 == 1):
			res = res * a
		a = a * a
		b //= 2
	return res
	  
t = int(inf.readline())
print("Case #1:", file = ouf)
n, k = map(int, inf.readline().split())

for mask in range(0, (1 << n)):
	x = (1 << (n - 1)) | (mask << 1) | 1
	ans = []
	for b in range(2, 11):
		cur = 0
		for i in range(0, n + 1):
			cur += pwr(b, i) * bit(x, i)
		lim = min(cur - 1, int(1.0e5))  
		flag = False
		for i in range(2, lim):
			if cur % i == 0:
				ans.append(i)
				flag = True
				break       
		if flag == False:                         
			x = -1
			break
	if x != -1: 
		cur = 0
		for i in range(0, n + 1):
			cur += pwr(10, i) * bit(x, i) 
		print(to2(x), *ans, file = ouf)
		k -= 1
		if k == 0: break
