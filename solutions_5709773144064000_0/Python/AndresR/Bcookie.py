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
	
def t(c,f,x,i):
	try:
		if i==0:
			return -1e50
		_t=2.+i*f
		return c/(_t-f)+x/_t*(1-_t/(_t-f))
	except:
		return "excpt"
	
data=get_input_lines()
number_case=int(data[0])
for n_case in range(1,number_case+1):
	line1=data[n_case].split()
	c=float(line1[0])
	f=float(line1[1])
	x=float(line1[2])
	if c>x:
		write_output(("Case #%d: %.9f\n")%(n_case,x/2.0))
	else:
		i=x/c-2/f
		print "(c,f,x)"
		print(c,f,x)
		print("i0=",i,"dt=",t(c,f,x,i))
		I=max(int(i),0)
		v=[t(c,f,x,I+j) for j in [-1,0,1]]
		print("i-1=",I-1,"dt=",v[0])
		print("i=",I,"dt=",v[1])
		print("i+1=",I+1,"dt=",v[2])
		# print "***"
		# for j in range(I+3):
			# print("i=",j-1,"dt=",t(c,f,x,j-1))
		#if not((I>0 and v[1]<0 and v[2]>0 and v[0]<0 and v[0]<v[1])or (I==0 and v[1]>0 and v[2]>0)):
		#	write_output("\n"*10+"ERROR NEXT!! ************************************************************************************************"+"\n"*10)
		ret=0
		k=2
		for j in range(I):
			# print ret
			ret+=1./k
			k+=f
		# print ret
		write_output(("Case #%d: %.9f\n")%(n_case,c*ret+x/k))
	
	
	