f=open('t.txt','r')
g=open('file.txt','w')

def getcombos(l,tot,sofar,neww):
	global d, fin, win
	if fin:   return 0
	if tot>0 and neww:
		if tot in d:
			win=[d[tot],sofar]
			fin=True
		else:
			d[tot]=sofar
	if not fin and len(l)>0:
		getcombos(l[1:],tot+l[0],sofar+[l[0]],True)
		getcombos(l[1:],tot,sofar,False)
	return 0

	


for i in range(1,1+int(f.readline())):
	nums=[int(j) for j in f.readline().split()[1:]]
	print nums
	d={}
	fin=False
	win=[]
	getcombos(nums,0,[],False)
	print 'Case #' + str(i) + ':'
	g.write('Case #' + str(i) + ':' + '\n')
	for j in win:
		for k in j:  
			print str(k) + ' ',
			g.write(str(k) + ' ')
		print 
		g.write('\n')

g.close()