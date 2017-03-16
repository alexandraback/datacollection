import sys
from math import sqrt

def get_input_lines():
	f=open(sys.argv[1],"r")
	ret=[(i[:-2] if i[-2:]=="\r\n" else (i[:-1] if i[-1]=="\n" else i)) for i in f.readlines()]
	f.close()
	return ret

def write_output(v):
	try:
		write_output.f
	except:
		write_output.f=open(sys.argv[1]+"_out","w")
	write_output.f.write(v)
	sys.stdout.write(v)
	
data=get_input_lines()
number_case=int(data[0])
for n_case in range(1,number_case+1):
	line1=data[n_case].split("/")
	p=float(line1[0])
	q=float(line1[1])
	bad=0
	x=1
	for i in range(40):
		x*=2
		#print(x,q,q/x,q%x)
		if q%x!=0:
			x/=2
			break
	y=q/x
	if p%y==0:
		p/=y
		q/=y
		n=0
		for i in range(40):
			if p*1.0/q>=1:
				print (p,"/",q)
				break
			else:
				n+=1
				q/=2.
		write_output(("Case #%d: %d\n")%(n_case,n))
	else:
		write_output(("Case #%d: impossible\n")%(n_case))
	
	