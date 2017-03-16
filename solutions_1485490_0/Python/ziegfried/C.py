import sys,os

class Obj:
	def __init__(self, count, t, n):
		self.count = count
		self.type = t
		self.n = n+1
	def __str__(self):
		return "(%s %d) %d of %d" % (self.__class__.__name__, self.n,self.count,self.type)
	def __repr__(self):
		return "(%s %d) %d of %d" % (self.__class__.__name__, self.n,self.count,self.type)

class Toy(Obj): pass
class Box(Obj): pass
		

def cmp(a,b):
	return b[0]-a[0]

caseCount = int(sys.stdin.readline().strip())
for case in range(1,caseCount+1):
	result = None

	N,M= [ int(x) for x in sys.stdin.readline().strip().split() ]

	boxes = []
	toys = []
	row = [ int(x) for x in sys.stdin.readline().strip().split() ]
	for i in range(N):
		boxes.append(Box( row[2*i], row[2*i+1],i ))
	row = [ int(x) for x in sys.stdin.readline().strip().split() ]
	for i in range(M):
		toys.append(Toy( row[2*i], row[2*i+1], i ))
	toys.reverse()
	boxes.reverse()
	result = 0

	curbox = boxes.pop()
	curtoy = toys.pop()
	while True:
		if curbox.type == curtoy.type and curbox.type != -1:
			r = min(curbox.count,curtoy.count)
			result += r
			curbox.count -= r
			curtoy.count -= r
			if curbox.count <= 0: 
				if len(boxes): curbox = boxes.pop()
				else: curbox.type = -1
			if curtoy.count <= 0: 
				if len(toys): curtoy = toys.pop()
				else:
					curtoy.type=-1
		else:
			if len(boxes) == 0 and len(toys) == 0: break
			options = []
			for i,b in enumerate(reversed(boxes)):
				if b.type == curtoy.type:
					options.append((min(curtoy.count, b.count), b))
			for i,t in enumerate(reversed(toys)):
				if t.type == curbox.type:
					options.append((min(curbox.count, t.count), t))
			if not len(options):
				if len(toys) is 0 or len(boxes) is 0: break
				curtoy = toys.pop()
				curbox = boxes.pop()
			else:
				options.sort(cmp)
				x = options[0][1]
				if isinstance(x, Toy):
					while True:
						curtoy = toys.pop()
						if curtoy is x: break
				if isinstance(x, Box):
					while True:
						curbox = boxes.pop()
						if curbox == x: break

	print "Case #%d: %d" % (case, result)