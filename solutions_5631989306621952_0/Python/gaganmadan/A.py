def genstr(s):
	out=''
	out=out+s[0]
	for i in range(1,len(s)):
		if (s[i]>=out[0]):
			out=s[i]+out
		else:
			out=out+s[i]
	return out

f=open('A-small.in')
n=f.readline()
g=open('A-small.out','w')
i=1
for line in f:
	temp=genstr(line)
	g.write("Case #"+str(i)+": "+temp)
	i=i+1