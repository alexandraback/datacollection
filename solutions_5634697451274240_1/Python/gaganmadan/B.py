def replace(s):
	s=s.replace('+','*')
	s=s.replace('-','+')
	s=s.replace('*','-')
	return s

def replaceflip(s):
	s=replace(s)
	return s[::-1]




def pancake(stri):
	if(stri==''):
		return 0
	elif(stri=='+'):
		return 0
	elif(stri[len(stri)-1]=='+'):
		return pancake(stri[0:len(stri)-1])
	elif(stri[0]=='-'):
		return pancake(replaceflip(stri))+1
	elif(stri=='-'):
		return 1
	else:
		striarr=list(stri)
		striarr[0]='-'
		i=1
		while(striarr[i]=='+'):
			striarr[i]='-'
			i=i+1
		stri=''.join(striarr)
		return pancake(replaceflip(stri))+2


f=open('B-large.in')
g=open('Blarge.txt','w')
n=int(f.readline())
i=1
for line in f:
	line=line.replace('\n','')
	g.write('Case #'+str(i)+': '+str(pancake(line))+'\n')
	i=i+1

	


f.close()
g.close()
