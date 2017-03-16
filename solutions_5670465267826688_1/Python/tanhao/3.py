class quad:
	def __init__(self, a, b):
		self.sign = a
		self.num = b
	def multiply(self, x):
		[sign1, num1] = A[self.num][x.num]
		return quad(self.sign * x.sign * sign1, num1)
		#return [self.sign * x.sign * sign1, num1]
	def equals(self, x):
		return (self.sign == x.sign) and (self.num == x.num)
	def output(self):
		print self.sign, self.num
cases = input()
A ={'1':{'1':[1,'1'], 'i':[1,'i'], 'j':[1,'j'], 'k':[1,'k']},
	'i':{'1':[1,'i'], 'i':[-1,'1'], 'j':[1,'k'], 'k':[-1,'j']},
	'j':{'1':[1,'j'], 'i':[-1,'k'], 'j':[-1,'1'], 'k':[1,'i']},
	'k':{'1':[1,'k'], 'i':[1,'j'], 'j':[-1,'i'], 'k':[-1,'1']}}
i = quad(1, 'i') 
j = quad(1, 'j')
k = quad(1, 'k')
def total(a):
	return reduce(lambda x, y:x.multiply(y), a, quad(1,'1'))
def g(a, tot, judge):
	
	now = quad(1,'1')
	for run in range(5):
		for (offset, item) in enumerate(a):
			now = now.multiply(item)
			if (now.equals(judge)):
				return [run, offset + 1]
	return [1232123212321232123212123212321232, 12321232121232123212321232123212321232123212321232]

def f(a, tot, judge):
	now = quad(1,'1')
	for run in range(5):
		for (offset, item) in enumerate(a):
			#now.multiply(item)
			now = item.multiply(now)
			if (now.equals(judge)):
				return [run, offset + 1]
	return [1232123212321232123212123212321232, 12321232121232123212321232123212321232123212321232]

for testCase in xrange(cases):
	(length, num) = map(int, raw_input().split())
	data = [quad(1,x) for x in raw_input()]
	#print data
	[roundi, cnti] = g(data, total(data), i)
	[roundj, cntj] = f(data[::-1], total(data), k)
	#print roundi, cnti
	#print roundj, cntj
	#result = (total(data).equals(quad(-1, '1'))) and (roundi + roundj < num) and (cnti + cntj < len(data))
	tot = quad(1,'1')
	for step in xrange(num % 4):
		tot = tot.multiply(total(data))
	#tot.output()
	result = (tot.equals(quad(-1, '1'))) and ((roundi + roundj) * len(data) + cnti + cntj < len(data) * num)
	print "Case #"+str(testCase + 1) + ": " +("YES" if result else "NO") 
	
