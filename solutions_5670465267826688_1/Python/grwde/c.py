class quat:
	def __init__(self, char,sign=1):
		self.sign=sign
		self.char=char
	def __neg__(self):
		return quat(self.char,-self.sign)
	def __hash__(self):
		return hash(self.char)+10*self.sign
	def __eq__(self,other):
		return self.char==other.char and self.sign==other.sign
	def __mul__(self,other):
		result=multiplicationTable[self.char][other.char]
		if self.sign==-1:
			result=-result
		if other.sign==-1:
			result=-result
		return result
	def __pow__(self,other):
		return reduce(lambda a,b:a*b, [self]*(other%4+4))
	def __str__(self):
		if self.sign==1:
			return self.char
		else:
			return "-{0}".format(self.char)
	def __repr__(self):
		return str(self)


multiplicationTable={
 '1':{'1': quat('1'),'i': quat('i'),'j': quat('j'),'k': quat('k')},
 'i':{'1': quat('i'),'i':-quat('1'),'j': quat('k'),'k':-quat('j')},
 'j':{'1': quat('j'),'i':-quat('k'),'j':-quat('1'),'k': quat('i')},
 'k':{'1': quat('k'),'i': quat('j'),'j':-quat('i'),'k':-quat('1')}	
}

def partial_prod(digits, mult):
	total=quat('1')
	for digit in digits:
		total=mult(total,digit)
		yield total


def minindex(periodproduct,digits, length, repeat, mult, target):
	best=length*repeat+1
	for index, partial in zip(range(1,length+1),
		partial_prod(digits,mult)):
		for n in range(0,min(4,repeat+1)):
			if mult(periodproduct**n, partial)==target:
				best=min(best,index+n*length)
	return best

def dkstra(length,repeat,digits):
	periodproduct=reduce((lambda a,b: a*b), digits)
	if not periodproduct**repeat==quat('i')*quat('j')*quat('k'):
		return False
	return (
	minindex(periodproduct,digits,length,
		repeat, (lambda a,b:a*b), quat('i'))+
	minindex(periodproduct,reversed(digits),length,
		repeat, (lambda a,b:b*a), quat('k'))<length*repeat)



T=int(raw_input())

for test in range(1,T+1):
	length,repeat=map(int, raw_input().split())
	digits=map(quat,raw_input())
	if dkstra(length,repeat,digits):
		print "Case #{0}: YES".format(test)
	else:
		print "Case #{0}: NO".format(test)