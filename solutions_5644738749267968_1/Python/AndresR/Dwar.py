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
	lines=data[1+(n_case-1)*3:1+n_case*3]
	line1=lines[1].split()
	line2=lines[2].split()
	n=len(line1)
	elems=[]
	for i in line1:
		elems.append((float(i),1))
	for i in line2:
		elems.append((float(i),-1))
	elems.sort(key=lambda x: x[0])
	kp=0
	kn=0
	rp=0
	rn=0
	for i in elems:
		if i[1]==1:
			kp+=1
			if kn>0:
				kn-=1
				rn+=1
		else:
			kn+=1
			if kp>0:
				kp-=1
				rp+=1
	write_output(("Case #%d: %d %d\n")%(n_case,rn,n-rp))
	
	
	