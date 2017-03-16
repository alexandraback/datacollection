import sys
import math

#allFS = []
allFS = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001]

def czyPalindrom(x):
	n = str(x)
	if len(n) == 1:
		return True
	pocz = 0
	kon = len(n) -1
	while True:
		if pocz < kon:
			if n[pocz] != n[kon]:
				return False
			else:
				pocz += 1
				kon -= 1
		else:
			return True

	
def genFS(pocz, kon):
	for i in xrange(pocz, kon+1):
		if czyPalindrom(i**2) and czyPalindrom(i):
			allFS.append(i**2)

#genFS(1,math.sqrt(10**14)+1)

testy = int(sys.stdin.readline())
for t in xrange(testy):
	linia =  sys.stdin.readline().split(' ')
	ile = 0
	for l in allFS:
		if long(linia[0]) <= l and l <= long(linia[1]):
			ile += 1
	print 'Case #%d: %d' % (t + 1, ile)
