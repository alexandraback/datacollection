def winner(X,R,C):
	if R*C%X != 0: return "RICHARD"
	if X==1: return "GABRIEL"
	if X==2: return "GABRIEL"
	if X==3:
		if min(R,C) == 1: return "RICHARD"
		return "GABRIEL"
	if X==4:
		if max(R,C) < 4: return "RICHARD"
		if min(R,C) <= 2: return "RICHARD"
		return "GABRIEL"
	if X==5:
		if max(R,C) < 5: return "RICHARD"
		if min(R,C) < 3: return "RICHARD"
		if R*C == 15: return "RICHARD"
		return "GABRIEL"
	if X==6:
		if max(R,C) < 6: return "RICHARD"
		if min(R,C) <= 3: return "RICHARD"
		return "GABRIEL"
	if X>=7:
		return "RICHARD"
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	X,R,C = [ int(a) for a in f.readline().strip().split()]
	print >>out, "Case #%d: %s"%(tc, winner(X,R,C))