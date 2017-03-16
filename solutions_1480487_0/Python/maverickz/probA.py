import sys
def main():

	fin=open(sys.argv[1],"r")
	fout=open("output1.out","w")
	t=int(fin.readline())
	for case in range(1,t+1):
		ls=[int(ele) for ele in fin.readline().split()]
		n=ls[0]
		s=ls[1:]
		X=sum(s)
		i=0
		res=[]
		res="Case #"+str(case)+": "
		while i<len(s):
			j=0
			acc=0
			while j<len(s):
				if(i!=j):
					acc+=s[i]-s[j]
				j+=1
			ans=float(X-acc)/(X*len(s))
			j=0
			acc=0
			compete=0
			while j<len(s):
				if(i!=j):
					if(((s[i]-s[j]+X*ans)*100)/X>=0.0):
						acc+=s[i]-s[j]
						compete+=1
				j+=1
			ans=float(X-acc)/(X*(compete+1))*100
			if ans<0.0:
				ans=0.0
			res+=str(ans)
			res+=" "
			i+=1
		res+="\n"
		fout.write(res)

if __name__=="__main__":
	main()
