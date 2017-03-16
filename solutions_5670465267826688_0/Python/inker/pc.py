class Token:
	def __init__(self, s):
		if s == "-1":	
			self.val = 3
			self.sign = -1
		elif s == "1":
			self.val = 3
			self.sign = 1
		else:
			if s[0] == '-':
				self.sign = -1
				s = s[1]
			else:
				self.sign = 1
			self.val = ord(s)-ord("i")
	
	def add(self, i):
		if self.val == 3:
			self.val = i.val
			self.sign *= i.sign
		elif i.val == 3:
			self.sign *= i.sign
		elif self.val == i.val:
			self.val = 3
			self.sign *= i.sign * -1
		elif (self.val+1) % 3 == i.val:
			self.val = 3 - self.val - i.val
			self.sign *= i.sign
		elif (self.val+2) % 3 == i.val:
			self.val = 3 - self.val - i.val
			self.sign *= i.sign * -1
		else:
			assert False
		return self
	
	def clone(self):
		x = Token("1")
		x.val = self.val
		x.sign = self.sign
		return x
	
	def toS(self):
		return ("-" if self.sign == -1 else "") + ("1" if self.val == 3 else chr(ord("i")+self.val))

def Run(s):
	#print s
	s = list(map(lambda x: Token(x), s))
	l = len(s)
	prefix = []
	pre = Token("1")
	#print "Prefix"
	for val in s:
		prefix.append(pre.add(val).clone())
		#print prefix[-1].toS()
	if pre.toS() != "-1":
		return False
	
	suffix = [0] * l
	#print "Suffix"
	pre = Token("1")
	for idx, val in reversed(list(enumerate(s))):
		pre = val.clone().add(pre)
		suffix[idx] = pre.clone()
		#print suffix[idx].toS()

	ans = False
	
	# Case 1
	for i in range(l-2):
		if prefix[i].val == 0 and prefix[i].sign == 1:
		#if prefix[i].val == 0:
			j = s[i+1].clone()
			for k in range(i+2, l):
				# suffix[k]
				#print "%s %s %s %d %d" % (prefix[i].toS(), j.toS(), suffix[k].toS(), i, k)
				if j.val == 1 and j.sign == 1 and suffix[k].val == 2 and  suffix[k].sign == 1:
				#if j.val == 1 and suffix[k].val == 2 and prefix[i].sign * j.sign * suffix[k].sign == 1:
					ans = True
					break
				j.add(s[k])
			if ans: break
	return ans
	

for case_no in range(int(raw_input())):
	l, x = map(int, raw_input().split())
	s = raw_input()
	assert l == len(s)

	T = 12
	if x > T:
		x = (x-T)%4+T
	if x > T:
		x -= 4

	'''
	while x > 0:
		if Run(s*x):
			ans = True
			break
		x -= 4
	else:
		ans = False
	'''
	ans = Run(s*x)

	# Case 2
	'''
	if not ans and x > 1:
		for i in range(l):
			if prefix[i].val == 0 and prefix[i].sign == 1:
				for k in range(l):
					if (suffix[k].val, suffix[k].sign) == (2, 1):
						j = suffix[i+1].clone() if i != l-1 else Token("1")
						j.add(prefix[k-1] if k != 0 else Token("1"))
						if (j.val, j.sign) == (1, 1):
							ans = True
							break
			if ans: break
	'''
	
	print "Case #%d: %s" % (case_no+1, "YES" if ans else "NO")

