def match(j,k):
	for i in range(len(j)):
		if j[i]!='?':
			if j[i]!=k[i]:
				return 0
				break

	return 1



for i in range(input()):
	print "Case #"+str(i+1)+":",
	a,b=raw_input().split()
	l=len(a)

	s=[]
	a_t=[]
	b_q=[]

	x=(10**l)-1
	if '?' in a and '?' in b:
		for t in range(x+1):
			r=str(t).zfill(l)
			#print "r: ",r
			if match(a,r):
				for q in range(x+1):
					w=str(q).zfill(l)
			#		print "w: ",w
					if match(b,w):
			#			print "difference: ",t,q,abs(t-q)
						s.append(abs(t-q))
						b_q.append(q)
						a_t.append(t)

	elif '?' not in a:
		r=int(a)
		#print "r: ",r
		for q in range(x+1):
			w=str(q).zfill(l)
	#		print "w: ",w
			if match(b,w):
	#			print "difference: ",r,q,abs(r-q)
				s.append(abs(r-q))
				b_q.append(q)
				a_t.append(r)

	elif '?' not in b:
		for t in range(x+1):
			r=str(t).zfill(l)
			#print "r: ",r
			if match(a,r):
				w=int(b)
			#	print "difference: ",t,w,abs(t-w)
				s.append(abs(t-w))
				b_q.append(w)
				a_t.append(t)



	c=min(s)
	#print "c: ",c
	#print "s: ",s
	#print "a_t: ",a_t
	#print "b_q: ",b_q

	index=[i for i,val in enumerate(s) if val==c]
	#print "inde: ",index

	newa=[]
	newb=[]
	news=[]

	for ad in index:
		news.append(s[ad])
		newa.append(a_t[ad])
		newb.append(b_q[ad])


	#print "news: ",news
	#print "newa: ",newa
	#print "newb: ",newb

	if news.count(c)>1:
		mt=min(newa)
		indexa=[newa[i] for i,val in enumerate(news) if val==c]
		if len(indexa)>1:
			indexb=[newb[i] for i,val in enumerate(news) if val==c]
			#print "fuck you"
			m_q=min(indexb)
			print str(newa[newb.index(m_q)]).zfill(l),str(m_q).zfill(l)
			#print
		else:
			print str(mt).zfill(l),str(newb[newa.index(mt)]).zfill(l)
	else:
		ind=s.index(c)
		print str(a_t[ind]).zfill(l),str(b_q[ind]).zfill(l)
		#print


