def check(n):
	L = []
	for base in range(2,11):
		l = 0
		nx = 1;
		tmp_n = n
		while tmp_n:
			l += (tmp_n%2)*nx
			nx *= base
			tmp_n /= 2
		kan = 2
		end = True
		while kan * kan < l and kan < 1000:
			if l % kan == 0:
				L.append(kan)
				end = False
				break
			kan += 1
		if end:
			return False,[]
	return (len(L) == 9), L[:]


t = int(raw_input())
print 'Case #%d:'%t
ll,n = map(int,raw_input().split())

beg1 = 2**(ll-1)+1
beg = beg1
K = []
while len(K) != n:
	a,b = check(beg)
	if a:
		K.append([beg]+b)
	beg += 2

import string

for t in K:
	print	str(bin(t[0]))[2:],string.replace(str(t[1:]),',','')[1:-1]

