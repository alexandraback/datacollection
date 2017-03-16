for t in xrange(1,1+int(raw_input())):
	n,m=map(int,raw_input().split())
	a=[map(int,raw_input().split())for _ in xrange(n)]
	rows=map(max,a)
	cols=map(max,zip(*a))
	print"Case #%d: %s"%(t,"YES"if a==[[min(row,col)for col in cols]for row in rows]else"NO")
