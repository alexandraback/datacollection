from math import ceil
inp=open('in.in','r')
f=open('out.out', 'w')
t=int(inp.readline().strip('\n'))
# t=input()
for tc in range(1,t+1):
	s=int(inp.readline().strip('\n'))
	# s=input()
	A=map(int, inp.readline().strip('\n').split())
	# A=map(int, raw_input().split())
	ans=1e9
	print tc
	for kfc in range(1,max(A)+1):
		tl=0
		for i in A:
			if i>kfc:
				tl+=(ceil(i/float(kfc))-1)
		# print ans
		ans=min(ans, int(tl)+kfc)
	f.write("Case #"+str(tc)+": "+str(ans)+"\n")
	# print "Case #%i: %i" % (tc, ans)