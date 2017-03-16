
def check(s):
	if s[0] != '1':
		return False
	for j in xrange(1,len(s)):
		if s[j] != '0':
			return False
	return True


def doit(s):
	times = (len(s)+1) / 2
	tmp = 0
	for j in xrange(times-1,-1,-1):
		tmp = tmp * 10 + int(s[j])
	newtmp = 0
	for j in xrange(times,len(s)):
		newtmp = newtmp * 10 + int(s[j])
	return tmp + newtmp

def newdoit(s):
	times = (len(s)+1) / 2
	tmp = 0
	for j in xrange(times-1,-1,-1):
		tmp = tmp * 10 + int(s[j])
	kkk = 1
	while kkk*10 <= tmp:
		kkk *= 10
	tmp -= kkk
	newtmp = tmp
	newstr = ""
	for j in xrange(len(s)):
		newstr += str(newtmp % 10)
		newtmp = newtmp / 10
	l1 = int(s)
	l2 = int(newstr)
	a1 = l1-l2+tmp
	l1 -= 1
	a2 = doit(str(l1))+1
	return min(a1,a2)

def newcheck(s):
	times = len(s) / 2
	loc = len(s)-1
	for j in xrange(times):
		if s[loc] != '0':
			return False
		loc -= 1
	return True
def newnewcheck(s):
	if s[0] == '1':
		return True
	return False

def ohcheck(s):
	if s[0] != '2':
		return False
	for j in xrange(1,len(s)):
		if s[j] != '0':
			return False
	return True
def gogogo(x):
	ans = 0
	if len(x) < 2:
		ans = int(x)
	elif check(x):
		ans = d[len(x)-1]
	elif newnewcheck(x):
		y = x[1:]
		ans = d[len(x)-1]+int(y)
		if x[-1] != '0':
			ans = min(ans,doit(x)+d[len(x)-1])
	elif ohcheck(x):
		ans = d[len(x)-1]+h[len(x)-1]
	elif newcheck(x):
		ans = newdoit(x) + d[len(x)-1]
	else:
		ans = doit(x) + d[len(x)-1]
	return ans

f = open("A.in","r")
g = open("Aout.txt","w")
t = int(f.readline())
d = [0 for i in xrange(16)]
h = [0 for i in xrange(16)]
d[1] = 10
cur = 10
for i in xrange(1,16):
	h[i] = cur
	cur *= 10
for i in xrange(2,16):
	d[i] = d[i-1] + h[i/2] + h[(i+1)/2] - 1
res = 0
for i in xrange(1,t+1):
	st = f.readline().split()
	res = gogogo(st[0])
	res = min(res,gogogo(str(int(st[0])-1))+1)
	if st[0][-1] != '1':
		res = min(res,gogogo(str(int(st[0])-1)[::-1])+2)

	g.write("Case #%d: %d\n" % (i,res))



