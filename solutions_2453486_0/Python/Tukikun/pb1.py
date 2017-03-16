f = open('input.dat', 'r')

nb = int(f.readline())

def statusline(l, oldst):
	if (oldst>=0):
		return oldst
	T = l.count('T')
	if l.count('X')+T>=4:
		return 0
	if l.count('O')+T>=4:
		return 1
	if l.count('.')>0:
		return -2
	return oldst

for i in range(nb):
	status = -1
	L = [0 for _ in range(4)]
	for j in range(4):
		line = f.readline()
		L[j]=list(line)
		status=statusline(L[j], status)
	if status<0:
		DL=[[L[k][k] for k in range(4)], [L[k][3-k] for k in range(4)]]
		status=statusline(DL[0],status)
		status=statusline(DL[1],status)
	if status<0:
		CL=[[L[k][j] for k in range(4)] for j in range(4)]
		for j in range(4):
			status=statusline(CL[j], status)
	
	if status == 0:
		print ("Case #%d: X won" % (i+1,));
	elif status == 1:
		print ("Case #%d: O won" % (i+1,));
	elif status == -2:
		print ("Case #%d: Game has not completed" % (i+1,));
	else:
		print ("Case #%d: Draw" % (i+1,));
	
	f.readline()



