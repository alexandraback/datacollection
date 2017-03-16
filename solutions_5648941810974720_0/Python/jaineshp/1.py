a=["zero","one","two","three","four","five","six","seven","eight","nine"]
'''
u - four
z - zero
w - two
g - eight
x - six
'''
unique=[0,2,4,6,8]
us=['z','w','u','x','g']
for i in range(len(a)):
	a[i]=list(a[i])
t=input()
tid=1
while t:
	t-=1
	s=raw_input()
	s=list(s.lower())
	freq=[0]*26
	for i in range(len(s)):
		freq[ord(s[i])-ord('a')]+=1
	ans=[]
	l=len(s)
	for i in range(len(unique)):
		if freq[ord(us[i])-ord('a')]>0:
			times=freq[ord(us[i])-ord('a')]
			for j in range(times):
				word=a[unique[i]]
				for k in range(len(word)):
					order=ord(word[k])-ord('a')
					freq[order]-=1
				ans.append(unique[i])
	for i in range(len(a)):
		ok=1
		while ok:
			backup=freq[:]
			for j in range(len(a[i])):
				order=ord(a[i][j])-ord('a')
				if freq[order]>0:
					freq[order]-=1
				else:
					ok=0
					break
			if ok:
				ans.append(i)
			else:
				freq=backup[:]
	if sum(freq)>0:
		print tid,"error"
		exit(0)
	ans.sort()
	print "Case #"+str(tid)+":",''.join(map(str,ans))
	tid+=1