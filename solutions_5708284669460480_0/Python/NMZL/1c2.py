def effectiveLength(word):
	if len(word)==1:
		return 1
	p2=1
	i=0
	while (p2+i)<len(word):
		if word[i]==word[p2+i]:
			i+=1
		else:
			i=0
			p2+=1
	return p2


t=input()
for i in xrange(t):
	[k,l,s]=[int(x) for x in raw_input().split(' ')]
	keyboard=raw_input()
	target=raw_input()
	eff_len=effectiveLength(target)
	num1=(s-(l-eff_len))/eff_len
	letter={}
	for char in keyboard:
		if char in letter.keys():
			letter[char]+=1
		else:
			letter[char]=1
	poss=1
	flag=1
	for char in target:
		if char not in letter.keys():
			flag=0
			break
		poss*=letter[char]/float(k)
	num2=poss*(s-l+1)
	print 'Case #{}: {}'.format(i+1, [0.0,num1-num2][flag])
