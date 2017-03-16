import sys

f=open('t.txt','r')
g=open('file.txt','w')

sys.setrecursionlimit(100000)

def perms(a,astart,b,bstart,sofar):
	global win,nlist,mlist
	if sofar>win:
		win=sofar
	if a==len(nlist) or b==len(mlist):
		return 0
	if nlist[a][1]==mlist[b][1]:
		if nlist[a][0]-astart==mlist[b][0]-bstart:
			perms(a+1,0,b+1,0,sofar+mlist[b][0]-bstart)
		elif nlist[a][0]-astart>mlist[b][0]-bstart:
			perms(a,astart+mlist[b][0]-bstart,b+1,0,sofar+mlist[b][0]-bstart)
		else:
			perms(a+1,0,b,bstart+nlist[a][0]-astart,sofar+nlist[a][0]-astart)
	else:
		perms(a+1,0,b,bstart,sofar)
		perms(a,astart,b+1,0,sofar)
	return 0
	


for i in range(1,int(f.readline())+1):
	[n,m]=[int(j) for j in f.readline().split()]
	nlist,mlist=[],[]
	temp=[int(j) for j in f.readline().split()]
	for j in range(0,len(temp),2):
		nlist.append([temp[j],temp[j+1]])
	temp=[int(j) for j in f.readline().split()]
	for j in range(0,len(temp),2):
		mlist.append([temp[j],temp[j+1]])
	#print nlist
	#print mlist
	win=0
	perms(0,0,0,0,0)
	print 'Case #' + str(i) + ': ' + str(win)
	g.write('Case #' + str(i) + ': ' + str(win) + '\n')
g.close()