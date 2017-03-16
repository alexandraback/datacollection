T=int(raw_input())
alph=['y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q']
for tt in range(T):
	line=raw_input()
	res=''
	for i in range(len(line)):
		if line[i]==' ':
			res+=' '
		else:
			c=alph[int(ord(line[i])-ord('a'))]
			res+=c
	print 'Case #%d:'%(tt+1),res

