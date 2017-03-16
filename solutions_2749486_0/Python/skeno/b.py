# /usr/bin/python
import sys

def reads(t): return map(t, input().split(" "))
def read(t) : return t(input())


T = read(int)

for t in range(1, T+1):
	[X, Y] = reads(int)
	
	if X < 0:
		xm = "EW"
	else:
		xm = "WE"
	if Y < 0:
		ym = "NS"
	else:
		ym = "SN"
		
	s = ""
	for i in range(0,abs(X)):
		s += xm
	for i in range(0,abs(Y)):
		s += ym
	print("Case #%d: %s" % (t, s))
