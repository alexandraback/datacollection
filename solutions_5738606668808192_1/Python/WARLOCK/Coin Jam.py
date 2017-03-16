import math
cnt = 0
Str = list("10000100000100000001000001000001")
print "Case #1:"

def conv(Str,b):
	r = 0
	x = len(Str) - 1
	for i in Str:
		if i == '1':
			r += b**x
		x -= 1
	a = min(10000,int(math.sqrt(r)))
	x = 2
	while x <= a:
		if r%x == 0:
			return x
		x += 1
	return -1
def valid(Str):
	l=[]
	for i in xrange(2,11):
		l.append(conv(Str,i))
		if l[-1] == -1:
			return False
	print "".join(Str),l
	return True

def precompute(Str,l=1):
	if l == 25:
		if valid(Str) == True:
			global cnt
			cnt += 1
			if cnt == 500:
				return True
			return False
		return False
	if precompute(Str,l+1) == True:
		return True
	if Str[l] == '1':
		Str[l] = '0'
	else:
		Str[l] = '1'
	if precompute(Str,l+1) == True:
		return True
	if Str[l] == '1':
		Str[l] = '0'
	else:
		Str[l] = '1'
	return False
precompute(Str)