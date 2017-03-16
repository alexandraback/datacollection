
f=open("C-small-1-attempt2.in","r")
g=open("OUT.txt","w")
T=int(f.readline())
for i in range(T):
	N=int(f.readline())
	hikers=[]
	for j in range(N):
		[D,H,M]=[int(k) for k in f.readline().split()]
		for gh in range(H):
			hikers.append((D,M+gh))
	hikers.sort()
	
	a=len(hikers)
	for hiker in range(len(hikers)):
		pos=hikers[hiker][0]
		t=(360-pos)/hikers[hiker][1]
		atemp=hiker
		for man in range(len(hikers)):
			if man!=hiker:
				v=hikers[man][1]
				po=hikers[man][0]
				tid=t
				
				if tid>=(360-po)/v:
					tid-=(360-po)/v
					if po<=pos+10**-10:
						atemp+=1
				while tid>=360/v:
					tid-=360/v
					atemp+=1
		
		a=min(a,atemp)
	
	g.write("Case #{}: {}\n".format(i+1,a))

f.close()
g.close()
