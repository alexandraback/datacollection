def sqrtd(a):
	b=1
	i=0
	while(b<a): b<<=1;i+=1
	i=i//2
	b=1<<i
	c=0
	r=0
	while(b>0):
		v=c+b*r*2+b*b
		if(v>a): b>>=1;continue
		c=v
		r+=b
	return r
def sqrtu(a):
	b=1
	i=0
	while(b<a): b<<=1;i+=1
	i=i//2
	b=1<<i
	c=0
	r=0
	while(b>0):
		v=c+b*r*2+b*b
		if(v>a): b>>=1;continue
		c=v
		r+=b
	if(c<a): r+=1
	return r
n=int(input())
lp=range(50)
for i in range(n):
	a,b=input().split()
	a=sqrtu(int(a))
	b=sqrtd(int(b))
	r=0
	if(a<=0) and (b>=0): r+=1
	if(a<=1) and (b>=1): r+=1
	if(a<=2) and (b>=2): r+=1
	if(a<=3) and (b>=3): r+=1
	for j in lp:
		c=int('1'+'0'*j+'1')
		if c<a: continue
		if c>b: break
		r+=1
	for j in lp:
		c=int('2'+'0'*j+'2')
		if c<a: continue
		if c>b: break
		r+=1
	for j in lp:
		c=int('1'+'0'*j+'1'+'0'*j+'1')
		if c<a: continue
		if c>b: break
		r+=1
	for j in lp:
		c=int('1'+'0'*j+'2'+'0'*j+'1')
		if c<a: continue
		if c>b: break
		r+=1
	for j in lp:
		c=int('2'+'0'*j+'1'+'0'*j+'2')
		if c<a: continue
		if c>b: break
		r+=1
	for j in lp:
		for k in lp:
			c=int('1'+'0'*j+'1'+'0'*k+'1'+'0'*j+'1')
			if c<a: continue
			if c>b: break
			r+=1
	for j in lp:
		for k in lp:
			c=int('1'+'0'*j+'1'+'0'*k+'1'+'0'*k+'1'+'0'*j+'1')
			if c<a: continue
			if c>b: break
			r+=1
	for j in lp:
		for k in lp:
			c=int('1'+'0'*j+'1'+'0'*k+'2'+'0'*k+'1'+'0'*j+'1')
			if c<a: continue
			if c>b: break
			r+=1
	for j in lp:
		for k in lp:
			for l in lp:
				c=int('1'+'0'*j+'1'+'0'*k+'1'+'0'*l+'1'+'0'*k+'1'+'0'*j+'1')
				if c<a: continue
				if c>b: break
				r+=1
	for j in lp:
		for k in lp:
			for l in lp:
				c=int('1'+'0'*j+'1'+'0'*k+'1'+'0'*l+'1'+'0'*l+'1'+'0'*k+'1'+'0'*j+'1')
				if c<a: continue
				if c>b: break
				r+=1
	for j in lp:
		for k in lp:
			for l in lp:
				for m in lp:
					c=int('1'+'0'*j+'1'+'0'*k+'1'+'0'*l+'1'+'0'*m+'1'+'0'*l+'1'+'0'*k+'1'+'0'*j+'1')
					if c<a: continue
					if c>b: break
					r+=1
	for j in lp:
		for k in lp:
			for l in lp:
				for m in lp:
					c=int('1'+'0'*j+'1'+'0'*k+'1'+'0'*l+'1'+'0'*m+'1'+'0'*m+'1'+'0'*l+'1'+'0'*k+'1'+'0'*j+'1')
					if c<a: continue
					if c>b: break
					r+=1
	print("Case #%d: %d"%(i+1,r))
