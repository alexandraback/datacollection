n = 16
m = 50
def toString(x):
	ret = ""
	for i in range(n):
		if x % 2 == 0:
			ret = '0' + ret
		else:
			ret = '1' + ret
		x /= 2
	return ret

def val(s, base):
	ret = 0
	for c in s:
		if c == '1':
			ret = ret * base + 1
		else:
			ret = ret * base
	return ret

v = 2**(n/2) - 1
print 'Case #1:'
for i in range(m):
	t = toString(v)[n/2:] + toString(v)[n/2:]
	myS = t
	for b in range(2,11):
		t += " " + str(val(toString(v),b))
		#print val(myS, b) % val(toString(v), b)
	print t
	v -= 2