from sys import stdin
def main():
	n=int(stdin.readline().strip())
	for i in range(n):
		m=int(stdin.readline().strip())
		f=[]
		s=[]
		for j in range(m):
			a,b=stdin.readline().strip().split()
			f.append(a)
			s.append(b)
		ans=0
		for j in range(len(f)):
			tmpf=f[0:j]+f[j+1:len(f)]
			tmps=s[0:j]+s[j+1:len(s)]
			if(tmpf.count(f[j])>0 and tmps.count(s[j])>0):
				ans+=1
		print('Case #'+str(i+1)+": "+str(ans))

main()

