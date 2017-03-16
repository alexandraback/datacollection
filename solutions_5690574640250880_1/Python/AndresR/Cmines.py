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
	line1=data[n_case].split()
	r=int(line1[0])
	c=int(line1[1])
	m=int(line1[2])
	b=c*r-m
	write_output(("Case #%d:\n")%n_case)
	print("(",r,c,")",m,b)
	if b==1:
		write_output("c"+"*"*(c-1)+"\n")
		for i in range(r-1):
			write_output("*"*c+"\n")
	elif r>=3 and c>=3:
		if b in [0,1,2,3,5,7]:
			write_output("Impossible\n")
			print("Imp 0,1,2,3,5,7")
		else:
			if b<=2*c+3:
				if b<9:
					k1=[2,3,3][(b-4)//2]
					k2=[0,0,2][(b-4)//2]
				else:
					k1=b//2-1
					k2=2+b%2
				write_output("c"+"."*(k1-1)+"*"*(c-k1)+"\n")
				write_output("."*k1+"*"*(c-k1)+"\n")
				write_output("."*k2+"*"*(c-k2)+"\n")
				for i in range(r-3):
					write_output("*"*c+"\n")
			else:
				k1=b%c
				if k1==1:
					k2=2
					k1=c-1
					y=(b-1)//c
				else:
					k2=0
					y=b//c
				write_output("c"+"."*(c-1)+"\n")
				for i in range(y-1):
					write_output("."*c+"\n")
				if r>y:
					write_output("."*k1+"*"*(c-k1)+"\n")
				if r>y+1:
					write_output("."*k2+"*"*(c-k2)+"\n")
				if r>y+2:
					for i in range(r-y-2):
						write_output("*"*c+"\n")
	elif r==1:
		if b<2:
			write_output("Impossible\n")
			print("Imp r1")
		else:
			write_output("c"+"."*(b-1)+"*"*(c-b)+"\n")
	elif c==1:
		if b<2:
			write_output("Impossible\n")
			print("Imp c1")
		else:
			write_output("c\n"+".\n"*(b-1)+"*\n"*(r-b))
	elif r==2:
		if b<4 or b%2==1:
			write_output("Impossible\n")
			print("Imp r2")
		else:
			write_output("c"+"."*((b//2)-1)+"*"*(c-(b//2))+"\n")
			write_output("."+"."*((b//2)-1)+"*"*(c-(b//2))+"\n")
	elif c==2:
		if b<4 or b%2==1:
			write_output("Impossible\n")
			print("Imp c2")
		else:
			write_output("c.\n"+"..\n"*((b//2)-1)+"**\n"*(r-(b//2)))
	
	
	
	