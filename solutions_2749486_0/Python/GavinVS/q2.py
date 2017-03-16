def f(goalx, goaly, curx, cury, step, path):
	#print "curx {0}, cury {1}, step {2}, path {3}".format(curx, cury, step, path)
	if curx == goalx and cury == goaly:
		return path
	if curx + step <= goalx:
		return f(goalx, goaly, curx+step, cury, step+1, path+"E")
	if curx - step >= goalx:
		return f(goalx, goaly, curx-step, cury, step+1, path+"W")
	if cury + step <= goaly:
		return f(goalx, goaly, curx, cury+step, step+1, path+"N")
	if cury - step >= goaly:
		return f(goalx, goaly, curx, cury-step, step+1, path+"S")

	#if here, within step of goal in x and y
	xdist = goalx - curx
	ydist = goaly - cury
	#print xdist, ydist

	if xdist > 0:
		return f(goalx, goaly, goalx, cury, step+2*xdist, path+"WE"*xdist)
	if xdist < 0:
		return f(goalx, goaly, goalx, cury, step-2*xdist, path+"EW"*(-xdist))
	if ydist > 0:
		return f(goalx, goaly, curx, goaly, step+2*ydist, path+"SN"*ydist)
	if ydist < 0:
		return f(goalx, goaly, curx, goaly, step-2*ydist, path+"NS"*(-ydist))

	print 'wat'
	return ""

T = int(raw_input())

for t in range(T):
	x, y = map(int, raw_input().split())
	
	print "Case #{0}: {1}".format(t + 1, f(x, y, 0, 0, 1, ""))