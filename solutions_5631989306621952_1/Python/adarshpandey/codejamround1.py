data=open("A-large (1).in","r")
s1=data.read()
s1=s1.split("\n")
t=int(s1[0])
for i in range(1,t+1):
	s=s1[i]#input()#s1[i]
	if(len(s)==1):
		print("Case #{0}: {1}".format(i,s))
	else:
		s2=s[0:1]
		for j in range(1,len(s)):
			if(s[j]>=s2[0]):
				s2=s[j]+s2
			else:
				s2=s2+s[j]
		print("Case #{0}: {1}".format(i,s2))