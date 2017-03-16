import sys

T=raw_input()

for i in range(1,int(T)+1):
	r,t = map(int,sys.stdin.readline().split())
	##t = raw_input()

	l = 0
	ri = int(t)

	while(l<ri):
		c=(ri+l)/2;
		if(2*int(r)*c+2*c*(c-1)+c<=int(t)):
			l=c
		else:
			ri=c
		
		if(2*int(r)*ri+2*ri*(ri-1)+ri>int(t)):
			ri=ri-1
		if(2*int(r)*(l+1)+2*(l+1)*(l)+l+1<=t):
			l=l+1
		if(ri==l): 
			break
		
	print "Case #" + str(i) + ": " + str(l)

	
