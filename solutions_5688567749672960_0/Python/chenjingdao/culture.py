
def inc(s,pos):
	if -pos > len(s):
		return "1"+s
	elif s[pos]=="9":
		if pos==-1:
			s=s[:pos]+"0"
		else:
			s=s[:pos]+"0"+s[pos+1:]
		return inc(s,pos-1)
	else:
		if pos==-1:
			s=s[:pos]+str(int(s[pos])+1)
		else:
			s=s[:pos]+str(int(s[pos])+1)+s[pos+1:]
		return s

dicts = {}
s="0"
dicts[s]=0
while len(s)<7:
	ss = inc(s,-1)
	if ss[::-1] in dicts:
		dicts[ss]=min(dicts[s]+1,dicts[ss[::-1]]+1)
	else:
		dicts[ss]=dicts[s]+1
	s=ss


f = open('a.in', 'r')
nTestCase = int(f.readline()[0:-1])
for numCase in range(0,nTestCase):
	N = f.readline()[0:-1]
	times = dicts[N]
	print "Case #"+str(numCase+1)+": "+str(times)


