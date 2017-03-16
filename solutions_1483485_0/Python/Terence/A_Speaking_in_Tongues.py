import sys

k = dict(zip('abcdefghijklmnopqrstuvwxyz \n','yhesocvxduiglbkrztnwjpfmaq \n'))
n = int(sys.stdin.readline())
for i in range(1,n+1):
	s = sys.stdin.readline()
	if(s[-1] == '\n'):
		s = s[:-1]
	s = ''.join(map(lambda x: k[x], s))
	print 'Case #%d: %s' % (i,s)
