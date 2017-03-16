with open("A-small-attempt0.in") as f:
#with open("A-large-practice.in") as f:
	dat = f.readlines()

def getsheeps(d,it,digs):
	n = d*it
	n = list(str(n))
	n = set(n)
	
	for nn in n:
		if int(nn) in digs:
			digs.remove(int(nn))

	if digs.__len__() == 0:
		return d*it
	return getsheeps(d,it+1,digs)
	
n = int(dat[0])
out = []
for i in range(1,n+1):
	d = int(dat[i])
	if d==0:
		d = "INSOMNIA"
	else:
		d = getsheeps(d,1, [i for i in range(10)])
		
	res = "Case #"+str(i)+": "+str(d)
	print(res)
	out.append(res)
	
of = open("out.txt","w")
of.write("\n".join(out))
of.close()



