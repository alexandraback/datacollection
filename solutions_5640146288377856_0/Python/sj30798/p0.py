import sys

t=int(input())
k=1
while t>0:
	t -= 1
	sys.stdout.write('Case #'+str(k)+': ')
	k+=1

	r, c, w = [int(a) for a in raw_input().split()]
	ans = 0
	if r != 1:
		ans += c/w*(r-1)
		r = 1
	if (r==1):
		ans+=c/w
		ans+=w-1
		if c%w==0:
			print ans
		else:
			print ans+1