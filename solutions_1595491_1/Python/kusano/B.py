for i in range(input()):
	t=map(int,raw_input().split())
	f=lambda a:sum(int(x>=max(t[2]*3-a,t[2]))for x in t[3:])
	print("Case #%s: %s"%(i+1,f(2)+min(f(4)-f(2),t[1])))
