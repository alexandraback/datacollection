results=dict()

def solve():
	global results
	a,b,c=map(int,(raw_input().split(" ")))
	print sol(a,b,min(max(a,b),c),str(bin(max(a,b,c))[2:]))



def sol(a,b,c,s):
	global results
	if s=='': return 1
	mx=2**(len(s)-1)
	if results.has_key((a,b,c)):
		return results[(a,b,c)]
	

	

	res=sol(min(a,mx),min(b,mx),min(c,mx),s[1:]);
	if mx<a:
		res+=sol(a-mx,min(b,mx),min(c,mx),s[1:])
	if mx<b:
		res+=sol(min(a,mx),b-mx,min(c,mx),s[1:])
	if mx<c and mx<a and mx<b:
		res+=sol(a-mx,b-mx,c-mx,s[1:])
	

	results[(a,b,c)]=res
	return res





n=input()
for i in range(n):
	print "Case #"+str(i+1)+":",
	solve()
