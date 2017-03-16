import sys

sys.stdin = open("A-small-attempt0.in","r")

def isgla(c):
	return c=="a" or c=="e" or c=="i" or c=="o" or c=="u"

def check(s,l):
	ln = len(s)
	res = 0
	for i in xrange(ln):
		if isgla(s[i]):
			res = 0
		else:
			res += 1
			if res==l: return True
	return False

def solve():
	s, l = sys.stdin.readline().strip().split()
	l = int(l)
	ln = len(s)
	r = 0
	for i in xrange(l,ln+1):
		for j in xrange(ln-i+1):
			sub = s[j:j+i]
			r += check(sub, l)
	return r
#for i in xrange(1,l+1):

t = int(raw_input())
for _t in xrange(t):
	print "Case #" + str(_t+1) + ":", solve()
