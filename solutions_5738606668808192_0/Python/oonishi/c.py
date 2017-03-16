#coding: utf8
# 2015 Round3 Problem Problem A. Fairland
# https://code.google.com/codejam/contest/4254486/dashboard

print(bin((1<<8) + 1))




def cnv(n, b):
	k = 1
	res = 0
	while n:
		if n%2:
			res += k
		k *= b
		n >>= 1
	return res
#print(cnv(n,3),cnv(11,3))

cnt = 0
n = (1<<8) + 1
print(bin(n))
for i in range((1<<7)+1, (1<<8)-1, 2):
	#print(bin(i*n), bin(i), bin(n))
	#print(i*n, n, i)
	for d in range(3, 11):
		#print(d, cnv(i*n, d), cnv(n, d), cnv(i*n, d)%cnv(n, d))
		if cnv(i*n, d)%cnv(n, d):
			raise
	print(cnv(i*n, 10), *[cnv(n,d) for d in range(2, 11)])
	cnt += 1
	if cnt == 50:
		break
print(cnt)	



