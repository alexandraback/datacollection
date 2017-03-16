import os
import sys
# print "OK"
T = int(sys.stdin.readline())
def match(a,b):
	if a==b:
		return True
	if a == 'T' or b =='T':
		return True
	return False

for t in range(T):
	m = []
	result = "Draw"
	for i in range(5):
		line = sys.stdin.readline()
		if "." in line:
			result = "Game has not completed"
		m.append( line )
	for ch in ('X','O'):
		for i in range(4):
			if match(m[i][0],ch) and match( m[i][1],ch) and match( m[i][2],ch) and match( m[i][3],ch):
				result = "%s won" % ch
				break
			if match(m[0][i],ch) and match( m[1][i],ch) and match( m[2][i],ch) and match( m[3][i],ch):
				result = "%s won" % ch
				break
			if match(m[0][0],ch) and match( m[1][1],ch) and match( m[2][2],ch) and match( m[3][3],ch):
				result = "%s won" % ch
				break
			if match(m[3][0],ch) and match( m[2][1],ch) and match( m[1][2],ch) and match( m[0][3],ch):
				result = "%s won" % ch
				break
		
	print "Case #%d: %s" % (t+1, result)

    
