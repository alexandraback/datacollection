t = int(raw_input())

E,R=0,0
def cal(v,l,r,s,d):
	if l>=r : return 0
	mx,idx =-1,-1
	for i in range(l,r):
		if v[i]>mx :
			mx ,idx= v[i],i
#	print v[l:r] ,":",idx,mx
	Y = max(d-(r-idx)*R,0)
	X = min(s+R*(idx-l),E) - Y
	eng = X
	ret = eng*v[idx]
#	print "l,r,s,d = ",l,r,s,d,"X,Y=",X,Y,"E = ",eng,"@",idx,"G = ",ret

	ret += cal(v,l,idx,s,X+Y) + cal(v,idx+1,r,Y+R,d)
	return ret

for ca in range(1,t+1):
	e,r,n = map(int,raw_input().split())
	r= min(r,e)
	E,R=e,r
	v = map(int,raw_input().split())
	ans = cal(v,0,n,e,r)
	print "Case #%d:" % ca, ans

