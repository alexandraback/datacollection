def get_chance(N,X,Y):
	#the first 1+(2+3)+...+(2A+(2A+1)) diamonds will form a full tree
	A = 0
	while 2*A+2*A+1 <= N:
		N -= 2*A+2*A+1
		A += 1
	
	#A=1: one diamond
	#A=2: 6 diamonds..
	if X+Y < 2*A:
		return 1
	if X+Y > 2*A:
		return 0
	
	
	#the next /*(2A+2)+(2A+3)*/ N diamonds will be split
	if N == 0:
		return 0
	if X==0:
		return 0 #otherwise A would get +1
	

	Y+=1
	#what are the chances to select at least Y diamonds from N that fallen from the sky, where p=0.5?
	#(binomial cumulative)
	#[ (N Y)+(N Y+1)+..+(N N) ] / 2^N
	
	#calc (N N):   http://en.wikipedia.org/wiki/Binomial_coefficient
	#ps[n][k] = (n k)
	ps = [ [1] + [0]*N ]
	for n in range(1,N+1):
		p_ = [1]
		for k in range(1,N+1):
			p_.append(ps[n-1][k-1]+ps[n-1][k])
		ps.append(p_)
	
	p = 0
	for i in range(Y,N+1):
		p += ps[N][i]
		#count also the other side: if enough diamonds got to the other side: 2*A+Y or more
		if i>=2*A+Y:
			if N-i < Y : #but only if it wasn't counted already
				p += ps[N][i]
	
	mult = 1
	while N>0:
		p /= 2.0
		N -= 1
	return p

def read_numbers(count=None):
	line = raw_input()
	tokens = [tok.strip() for tok in line.split(" ")]
	
	if count!=None:
		assert len(tokens) == count
	
	return map(int, tokens)

def main():
	T = read_numbers(1)[0]
	for i in range(T):
		N,X,Y = read_numbers(3)
		num = get_chance(N,X,Y)
		assert num<=1
		print "Case #%d: %f" % (i+1,num)

main()
