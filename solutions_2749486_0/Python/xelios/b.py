import sys

sys.stdin = open("B-small-attempt0.in","r")

def solve():
	dx,dy =map(int, sys.stdin.readline().strip().split())
	if dx>0:
		for i in xrange(dx): sys.stdout.write("WE")
	else:
		for i in xrange(-dx): sys.stdout.write("EW")
	if dy>0:
		for i in xrange(dy): sys.stdout.write("SN")
	else:
		for i in xrange(-dy): sys.stdout.write("NS")
	return ""
t = int(raw_input())
for _t in xrange(t):
	print "Case #" + str(_t+1) + ": ", solve()