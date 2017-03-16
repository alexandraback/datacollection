class Quaternion(object):
	I = 1
	J = 2
	K = 3
	def __init__(self, type = 0, sign = 1):
		self.type, self.sign = type, sign

	def __str__(self):
		if self.type == Quaternion.I:
			rep = 'I'
		elif self.type == Quaternion.J:
			rep = 'J'
		elif self.type == Quaternion.K:
			rep = 'K'
		else:
			rep = '1'
		if self.sign < 0:
			return '-'+rep
		else:
			return rep

	def __eq__(self, o):
		return (self.type == o.type and self.sign == o.sign)

	def __mul__(self, o):
		type = self.type ^ o.type
		sign = self.sign * o.sign
		if (self.type - o.type in [-2,0,1] and self.type * o.type != 0):
			sign = -sign
		return Quaternion(type, sign)
		
	def __pow__(self, k):
		k %= 4
		res = Quaternion(0,1)
		for i in range(k):
			res *= self
		return res

def quat(s):
	if s[0] == '-':
		sign = -1
		s = s[1:]
	else:
		sign = 1
	if s.lower() == 'i':
		type = Quaternion.I
	elif s.lower() == 'j':
		type = Quaternion.J
	elif s.lower() == 'k':
		type = Quaternion.K
	elif s.lower() == '1':
		type = 0
	else:
		raise ValueError
	return Quaternion(type, sign)

#fi = open('C.in','r')
#fo = open('C.out','w')
fi = open('C-small-attempt0.in','r')
fo = open('C-small-attempt0.out','w')
#fi = open('C-large.in','r')
#fo = open('C-large.out','w')
t = int(fi.readline())
for _ in range(t):
	m,x = map(int,fi.readline().split())
	s = fi.readline().strip()
	l = r = 0
	vl, vr, vt = quat('1'),quat('1'),quat('1')
	for c in s*4:
		vl = vl * quat(c)
		l += 1
		if vl == quat('i'):
			break
	for c in (s*4)[::-1]:
		vr = quat(c)*vr
		r += 1
		if vr == quat('k'):
			break
	for c in s:
		vt = vt * quat(c)
	vt **= x
	
	if l < 4*m and r < 4*m and l+r < m*x and vt == quat('-1'):
		fo.write('Case #%d: YES\n' % (_+1))
	else:
		fo.write('Case #%d: NO\n' % (_+1))
fi.close()
fo.close()
