###MOVE END DIGITS TO BACK POSITION DIGITS
def digitsToMovePosition(A,B):
	power = 1
	temp = A
	while (temp >= 10):
		power *= 10
		temp /= 10
	
	result = 0
	for n in range(A, B+1):
		temp = n
		while (true):
			temp = (temp / 10) + ((temp % 10) * power)
			if (temp == n):
				break
			if (temp > n and temp <= B):
				result+=1
	return result


###BUILD A DICTIONARY INTO A TREE
def treeByDictionary():
	import sys
	sys.setrecursionlimit(10000)

	with open('garbled_email_dictionary.txt', 'r') as file:
		words = file.read().split()

	def maketree(words):
		def addprefix(tree, w):
			for i in range(len(w)):
				c = w[i]
				if c not in tree:
					tree[c] = {}
				tree = tree[c]
			tree[''] = w

		tree = {}
		for w in words:
			addprefix(tree, w)
		return tree

	from collections import namedtuple
	State = namedtuple('State', ['left', 'tree', 'change', 'cost'])

	prefix = maketree(words)

	def _subsolve(message, tree, change):
		if not message:
			if '' in tree:
				return 0
			else:
				return None

		options = []
		if change > 0:
			# the letter must be identical
			c = message[0]
			if c in tree:
				options.append((message[1:], tree[c], change - 1, 0))
			if '' in tree and c in prefix:
				options.append((message[1:], prefix[c], change - 1, 0))
		else:
			# allow changes
			for c in tree:
				if c != '':
					if c == message[0]:
						options.append((message[1:], tree[c], 0, 0))
					else:
						options.append((message[1:], tree[c], 4, 1))

				else:
					# new word
					for d in prefix:
						if d == message[0]:
							options.append((message[1:], prefix[d], 0, 0))
						else:
							options.append((message[1:], prefix[d], 4, 1))

		best = None

		for (oleft, otree, ochange, cost) in options:
			if best is None or best > cost:
				tmp = subsolve(oleft, otree, ochange)
				if tmp is not None:
					best = tmp + cost if ((best is None) or (tmp + cost < best)) else best
		return best

	subd = {}
	def subsolve(message, tree, change):
		h = (message, id(tree), change)
		if h not in subd:
			subd[h] = _subsolve(message, tree, change)
		return subd[h]

	def solve(message):
		return subsolve(message, prefix, 0)

	with open('C-large.in', 'r') as file:
		T = int(file.readline())
		for case in range(1, T+1):
			subd = {}
			message = file.readline().strip()
			print 'Case #{}: {}'.format(case, solve(message))


### FUNCTION TO DISPLAY ANY ARRAY BY JUMPIMG LINE
def displayArray(my_array):
	for i in range(len(my_array)):
		print i

### FUNCTION EQUAL TO VALUE N BY BINARY SEARCH
def binarySearch(N):
	low, high = -1, 100000000
	while  low + 1 < high:
		middle = (high+low)/2
		if f(middle)>= N:
			high = middle
		else:
			low = middle

	#print 'low, high', low, high
	served = binarySearch(high)

### MANIPULATE STRING
def manipulateString():	
	str1 = "mystring"
	list1 = list(str1)
	list1[5] = 'u'
	str1 = ''.join(list1)
	print(str1)

### BIT MANIPULATION
def bitManipulation():
	a = map(lambda x: int(x, 2), raw_input().split())
	b.sort()

	ans = inf
	for i in xrange(n):
		c = []
		diff = a[0] ^ b[i]  ###USE XOR IN PYTHON #from operator import xor

		for j in xrange(n):
			c.append(a[j] ^ diff)
		c.sort()
		if b == c: ans = min(ans, bin(diff).count('1'))
	if ans == inf:
		print 'NOT POSSIBLE'
	else:
		print ans
	return


### CHECK IN A FULL BINARY TREE
def CheckInATree():
	N = int(raw_input())
	V = [[] for _ in xrange(N)]

	for i in xrange(N-1):
		V[a-1].append(b-1)
		V[b-1].append(a-1)

	best = 1

	for root in xrange(N):
		Q = [root]
		P = range(N)
		P[root] = None

		for q in Q:
			for v in V[q]:
				if v != P[q]:
					Q.append(v)
					P[v] = q

		Q.reverse()
		A = [[] for i in xrange(N)]

		for q in Q:
			val -1
			if len(A[q]) >= 2:
				A[q].sort()
				val = sum(A[v][-2:])+1

			if P[q] != None:
				A[P[q]].append(val)
			else:
				if val> best: best = val
	print 'Case #%d: %d' % (T, N-best)


### THE DATA ARE GROUPED
from itertools import *
from operator import itemgetter
def groupbyData():
	d = dict(a=1, b=2, c=1, d=2, e=1, f=2, g=3)
	di = sorted(d.iteritems(), key=itemgetter(1))
	for k, g in groupby(di, key=itemgetter(1)):
		print k, map(itemgetter(0), g)

###REDUCE THE NUMBER OF LETTERS TO ITS MINIMUM
def reduceMinLettersInTheWord():
	"".join(c for (c,x) in itertools.groupby(sorted(list('mmaaaaaawwwwwwwmmmm'))))
	# output = maw
def numberOfOccurences():
	res = []
	for (c,it) in itertools.groupby(s):
		r = 0
		for a in it:
			r +=1
		res.append(r)
	return res

### "permutations example:"
def permutationWithItertools():
	i = 1
	for n in itertools.permutations([ 1, 2, 3],3):
		print i,":",n
		i += 1
# output: 
#1 : (1, 2, 3)
#2 : (1, 3, 2)
#3 : (2, 1, 3)
#4 : (2, 3, 1)
#5 : (3, 1, 2)
#6 : (3, 2, 1)

def combinationsWithItertools():
	i = 1
	for n in itertools.combinations("ABCD",3):
		print i,"[:]",n
		i += 1
#output:
#1 [:] ('A', 'B', 'C')
#2 [:] ('A', 'B', 'D')
#3 [:] ('A', 'C', 'D')
#4 [:] ('B', 'C', 'D')
#combinations_with_repla

### CHECK AVAILABLE NEIGHBOURS WHEN TRAVELLING
def availneighbour(a):
	return sorted([(A[i],i) for i in E[a] if used[i]==0])


### REDUCING FRACTION
def fraction():
	from fractions import Fraction
	Fraction(123, 31488).numerator
	Fraction(123, 31488).denominator




### START THE PROGRAM
for tc in xrange(1, int(raw_input())+1):
	#print 
	print "Case #{}:".format(tc),

	#N, P = map(int, raw_input().split())
	R, C, W = map(int, raw_input().split())

	res = W + C/W + (-1 if C%W == 0 else 0)


	print res*R



	#OUTPUT FOR THE RESULT:
	#if y != '':
	#else:
	#print "Case #{}: ".format(tc) + "{0:.6f}".format(y)
		
	
