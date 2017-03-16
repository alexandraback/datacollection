def toggle(l):
	i=0
	while i<len(l):
		if l[i]=='+':
			l=l[:i]+'-'+l[i+1:]
		else:
			l=l[:i]+'+'+l[i+1:]
		i+=1
	return l

t=int(input(''))
for x in range(t):
	s=input('')
	i=len(s)-1
	check=False
	checkind=0
	count=0
	while i>=0:
		#print(s,' ',check,' ',checkind,' ',i)
		if s[i]=='-':
			check=True
			checkind=i
		if s[i]=='+' and check:
			check=False
			s=toggle(s[:checkind+1])+s[checkind+1:]
			count+=1
			i+=1
		i-=1
		#print(s,' ',check,' ',checkind,' ',i)
	if check:
		s=toggle(s[:checkind+1])+s[checkind+1:]
		count+=1
	print('Case #{}: {}'.format(str(x+1),str(count)))
