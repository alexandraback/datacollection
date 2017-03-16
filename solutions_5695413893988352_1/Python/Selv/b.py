n = int(raw_input())

def eq(c,j,t):
	x = zip(c,j)
	ans = ''

	for a,b in x:
		if a != '?' and b != '?':
			if a == b:
				ans += a
			else:
				return False
		elif a != '?' and b == '?':
			ans += a
		elif a == '?' and b != '?':
			ans += b
		elif a == '?' and b == '?':
			ans += '0'
		else:
			print 'WTF'
	print 'Case #%d:'%t,ans,ans
	return True
	

def minn(c):
	def f(a):
		if a == '?':
			return '0'
		else:
			return a
	return ''.join(map(f,c))


def maxx(c):
	def f(a):
		if a == '?':
			return '9'
		else:
			return a
	return ''.join(map(f,c))

def eee(c,j):
	x = zip(c,j)
	ans = ''

	for a,b in x:
		if a != '?' and b != '?':
			if a == b:
				ans += a
			else:
				return False
		elif a != '?' and b == '?':
			ans += a
		elif a == '?' and b != '?':
			ans += b
		elif a == '?' and b == '?':
			ans += '0'
		else:
			print 'WTF'
	return ans

def sim(a,b):
	if a == '?' or b == '?' or a == b:
		return True
	return False

for t in range(n):
	c,j = raw_input().split()

	if eq(c,j,t+1):
		continue
	print 'Case #%d:'%(t+1),

	ans = (999999999999999999999, 0,0,'','')

	pref = ''

	for i in range(len(c)):
	
		if c[i] == '?' and j[i] == '?':
			a = pref + '0' + maxx(c[i+1:])
			b = pref + '1' + minn(j[i+1:])
			ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))

			a = pref + '1' + minn(c[i+1:])
			b = pref + '0' + maxx(j[i+1:])
			ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))

		elif c[i] == '?' and j[i] != '?':
			if j[i] != '0':
				a = pref + chr(ord(j[i])-1) + maxx(c[i+1:])
				b = pref  + minn(j[i:])
				ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))
			if j[i] != '9':
				a = pref + chr(ord(j[i])+1) + minn(c[i+1:])
				b = pref + maxx(j[i:])
				ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))
		elif c[i] != '?' and j[i] == '?':
			if c[i] != '0':
				b = pref + chr(ord(c[i])-1) + maxx(j[i+1:])
				a = pref  + minn(c[i:])
				ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))
			if c[i] != '9':
				b = pref + chr(ord(c[i])+1) + minn(j[i+1:])
				a = pref + maxx(c[i:])
				ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))
		elif c[i] != '?' and j[i] != '?':
			if True:
				a = pref + maxx(c[i:])
				b = pref  + minn(j[i:])
				ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))
			if True:
				a = pref + minn(c[i:])
				b = pref + maxx(j[i:])
				ans = min(ans,(abs(int(a)-int(b)),int(a),int(b),a,b))
		if sim(c[i],j[i]) == False:
			break
		pref += eee(c[i],j[i])

	a,b,c,d,e = ans
	print d,e
