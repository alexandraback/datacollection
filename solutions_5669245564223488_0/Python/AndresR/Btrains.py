import sys
from math import sqrt, factorial

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
	
def check_word(y):
	u=set()
	for t in range(len(y)-1):
		if y[t]!=y[t+1]:
			u.add(y[t])
			if y[t+1] in u:
				return 1
	return 0
	
data=get_input_lines()
number_case=int(data[0])
data=data[1:]
for n_case in range(1,number_case+1):
	n=int(data[0])
	s=data[1].split(" ")
	elem=0
	used=set()
	bad=0
	cases=1
	while len(s)>0 and not bad:
		x=s.pop()
		bad=check_word(x)
		used.update(set(x)-set((x[0],x[-1])))
		if bad:
			break
		while not bad:
			xf=x[-1]
			x0=x[0]
			foundf=""
			found0=""
			setf=0
			set0=0
			s1=[]
			for y in s:
				if not used.isdisjoint(y):
					bad=1
					break
				bf=xf in y
				b0=x0 in y
				if b0 and bf and x0!=xf:
					bad=1
					break				
				if bf:
					if y[0]!=xf:
						bad=1
					else:
						if len(set(y))!=1:
							if foundf!="":
								bad=1
								break
							else:
								foundf=y
						else:
							setf+=1
				if b0:
					if y[-1]!=x0:
						bad=1
						break
					else:
						if bad:
							if x0==xf:
								bad=0
								#print("bingo", y, x0)
							else:
								break
					if len(set(y))!=1:
						if found0!="":
							bad=1
							break
						else:
							found0=y
					else:
						set0+=1		
				if bad:
					break
				if not bf and not b0:
					s1.append(y)
			s=s1
			#print (x, s,xf,x0,setf,set0,used,"F",foundf,"0",found0)
			if bad:
				break
			if foundf=="" and found0=="" and setf==0 and set0==0:
				break
			if x0!=xf:
				if  foundf!="":
					bad=check_word(foundf)
					used.update(set(foundf)-set(foundf[-1]))
					cases*=factorial(setf)
					xf=foundf[-1]
				elif setf!=0:
					cases*=factorial(setf)
					used.add(xf)
				if  found0!="":
					if not set(foundf).isdisjoint(found0):
						bad=1
						break
					bad=check_word(found0)
					used.update(set(found0)-set(found0[0]))
					cases*=factorial(set0)
					x0=found0[0]
				elif set0!=0:
					cases*=factorial(set0)
					used.add(x0)
			else:
				cases*=factorial(set0+1)
				bad=check_word(found0) or check_word(foundf)
				used.add(x0)
				if  foundf!="":
					used.update(set(foundf)-set(foundf[-1]))
					xf=foundf[-1]
				if found0!="":
					used.update(set(found0)-set(found0[0]))
					x0=found0[0] 
		elem+=1
	print(elem)
	cases*=factorial(elem)
	cases %= 1000000007
	if not bad:
		write_output(("Case #%d: %d\n")%(n_case,cases))
	else:
		write_output(("Case #%d: 0\n")%(n_case))
	data=data[2:]
	
	