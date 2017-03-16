import random 
T = int(raw_input())
N, K = [int(_) for _ in raw_input().split()]

print "Case #1:"

def rand_str(l, p = 0) :
	res = ""
	for i in range(l) :
		if i == 0 or i == l-1 or p == 1:
			res += "1"
		else :
			res += str(random.randint(0, 1))
	return res

def convert(val, base) :
	new_value = 0
	for c in val :
		new_value = new_value * base + int(c)
	return new_value

data = []

def divisor(X) :
	p = 2
	while p * p <= X :
		if X % p == 0 :
			return p
		p = p + 1
	return -1

cnt = 0

while K > 0 and cnt < 1000 :
	cnt = cnt + 1

	val = rand_str(N)
	if data.count(val) > 0 :
		continue

	div = []
	for base in range(2, 11) :
		div.append(divisor(int(convert(val, base))))
		if div[len(div)-1] == -1 :
			break

	if div[len(div)-1] == -1 :
		continue

	data.append(val)
	res = str(val) + " "
	for x in div :
		res += str(x) + " "
	print res
	K = K - 1