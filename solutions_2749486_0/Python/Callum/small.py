def path(x,y):
	nx=abs(x)
	ny=abs(y)
	curlen=1
	curx=0
	cury=0
	path=''
	if curx!=nx:
		while curx<=(nx-curlen):
			path+='E'
			curx+=curlen
			curlen+=1
		state=0
		while curx!=nx:
			if state==0:
				path+='W'
				curx-=curlen
				curlen+=1
			else:
				path+='E'
				curx+=curlen
				curlen+=1
			state=1-state
	if cury!=ny:
		while cury<=(ny-curlen):
			path+='N'
			cury+=curlen
			curlen+=1
		state=0
		while cury!=ny:
			if state==0:
				path+='S'
				cury-=curlen
				curlen+=1
			else:
				path+='N'
				cury+=curlen
				curlen+=1
			state=1-state
	if x<0:
		path=path.replace('E','q')
		path=path.replace('W','E')
		path=path.replace('q','W')
	if y<0:
		path=path.replace('N','q')
		path=path.replace('S','N')
		path=path.replace('q','S')
	return path
lines=[i.replace('\n','') for i in open('B-small-attempt0.in','r').readlines()[1:]]
out=open('output.txt','w')
for i in range(len(lines)):
	t=lines[i].split()
	x=int(t[0])
	y=int(t[1])
	out.write(('Case #{0}: '+path(x,y)+'\n').format(i+1))