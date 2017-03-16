d={
	('1','1'):'1', ('1','i'):'i', ('1','j'):'j', ('1','k'):'k',
	('i','1'):'i', ('i','i'):'-1', ('i','j'):'k', ('i','k'):'-j',
	('j','1'):'j', ('j','i'):'-k', ('j','j'):'-1', ('j','k'):'i',
	('k','1'):'k', ('k','i'):'j', ('k','j'):'-i', ('k','k'):'-1',

	('-1','1'):'-1', ('-1','i'):'-i', ('-1','j'):'-j', ('-1','k'):'-k',
	('-i','1'):'-i', ('-i','i'):'1', ('-i','j'):'-k', ('-i','k'):'j',
	('-j','1'):'-j', ('-j','i'):'k', ('-j','j'):'1', ('-j','k'):'-i',
	('-k','1'):'-k', ('-k','i'):'-j', ('-k','j'):'i', ('-k','k'):'1'

}

def negate(s):
	return s[1] if len(s)==2 else '-'+s

inp=open('in.in','r')
f=open('out.out', 'w')
t=int(inp.readline().strip('\n'))
# t=input()
for tc in range(1,t+1):
	ip=jp=kp=False
	l,x=map(int, inp.readline().strip('\n').split())
	bs=inp.readline().strip('\n')*x
	S=[None]*len(bs)
	S[0]=bs[0]
	for i in range(1, len(S)):
		S[i]=d[(S[i-1], bs[i])]

	for i in S:
		if i=='i':
			# i found
			ip=True
		if ip and i=='k':
			# j found
			jp=True
	if S[-1]=='-1':
		# k found
		kp=True

	if ip and jp and kp: ans = 'YES'
	else: ans = 'NO'

	f.write("Case #"+str(tc)+": "+str(ans)+"\n")
	# print "Case #%i: %s" % (tc, ans)
