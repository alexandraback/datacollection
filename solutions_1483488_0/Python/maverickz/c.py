import sys
def check(n,a,b):
	ndigit=0
	temp=n
	res=0
	while(temp>0):
		ndigit+=1
		temp/=10
	p=10
	k=1
	ls=[]
	for i in range(ndigit):
		k*=10
	for i in range(1,ndigit):
		temp=n
		back=temp%p
		front=temp/p
		m=back*(k/p)+front
		if(back<(p/10)):
			p*=10
			continue
		if(m<=b and m>n):
			if m not in ls:
				res+=1
				ls.append(m)
		p*=10
	return res

def main():
	if(len(sys.argv)<2):
		print "usage : c.py input.in"
	inp=open(sys.argv[1],"r")
	op=open("output.out","w")
	t=int(inp.readline())
	case=1
	while(case<=t):
		a,b=[int(ele) for ele in inp.readline().split()]
		res=0
		for i in range(a,b+1):
			res+=check(i,a,b)
		op.write("Case #"+str(case)+": "+str(res)+"\n")
		case+=1
if __name__=="__main__":
	main()
