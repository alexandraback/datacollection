import sys
def maxscore(sc,s):
	if s==1:
		x=(sc+4)/3
		err=(sc+4)%3
		if(x-1<0 or (x-1==0 and err<2)):
			x=-1
	else:
		x=(sc+2)/3
		err=(sc+2)%3
		if(x==0 and err<2):
			x=-1
	return x	
def main():
	if(len(sys.argv)<2):
		print "Usage : b input.in"
		return
	inp=open(sys.argv[1],"r")
	op=open("output.out","w")
	t=int(inp.readline())
	case=1
	while(case<=t):
		ls=[int(ele) for ele in inp.readline().split()]
		n=ls[0]
		s=ls[1]
		p=ls[2]
		scores=ls[3:]
		res=0
		i=0
		while i<n:
			sc=scores[i]
			if(maxscore(sc,0)>=p):
				res+=1
				i+=1
				continue
			if(s>0 and maxscore(sc,1)>=p):
				res+=1
				s-=1
			i+=1
		op.write("Case #"+str(case)+": "+str(res)+"\n")
		case+=1

if __name__=="__main__":
	main()
