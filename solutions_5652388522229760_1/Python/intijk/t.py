import sys
lines=sys.stdin.readlines();
n=int(lines[0]);
def calc(i):
	count=[0] * 10
	t=0;
	last=0;
	s=1;
	while True:
		stri=str(i*s)
		done=False
		for c in stri:
			if count[ord(c)-ord('0')]==0:
				count[ord(c)-ord('0')]=1
				t+=1;
				if t==10:
					last=i*s;
					done=True;
					break;
		if(done):
			break;
		s=s+1
	return str(last)

for i in range(1,n+1):
	num=int(lines[i])
	if num>0:
		r=calc(num)
	else: 
		r="INSOMNIA"
	print "Case #%d: %s" % (i, r)

